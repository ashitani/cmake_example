#include <GLFW/glfw3.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

// from glfw tutorial
// and http://nn-hokuson.hatenablog.com/entry/2017/02/24/171230

GLuint createShader()
{
    //バーテックスシェーダのコンパイル
    GLuint vShaderId = glCreateShader(GL_VERTEX_SHADER);
    string vertexShader = R"#(
    attribute vec3 position;
    attribute vec2 uv;
    varying vec2 vuv;
    void main(void){
        gl_Position = vec4(position, 1.0);
        vuv = uv;
    }
    )#";
    const char* vs = vertexShader.c_str();
    glShaderSource(vShaderId, 1, &vs, NULL);
    glCompileShader(vShaderId);

    //フラグメントシェーダのコンパイル
    GLuint fShaderId = glCreateShader(GL_FRAGMENT_SHADER);
    string fragmentShader = R"#(
    varying vec2 vuv;
    uniform sampler2D texture;
    void main(void){
        gl_FragColor = texture2D(texture, vuv);
    }
    )#";
    const char* fs = fragmentShader.c_str();
    glShaderSource(fShaderId, 1, &fs, NULL);
    glCompileShader(fShaderId);

    //プログラムオブジェクトの作成
    GLuint programId = glCreateProgram();
    glAttachShader(programId,vShaderId);
    glAttachShader(programId,fShaderId);

    // リンク
    glLinkProgram(programId);
    glUseProgram(programId);

    return programId;
}

GLuint loadTexture(string filename, int width, int height)
{
    // テクスチャIDの生成
    GLuint texID;
    glGenTextures(1, &texID);

    // ファイルの読み込み
    std::ifstream fstr(filename, std::ios::binary);
    const size_t fileSize = static_cast<size_t>(fstr.seekg(0, fstr.end).tellg());
    fstr.seekg(0, fstr.beg);
    char* textureBuffer = new char[fileSize];
    fstr.read(textureBuffer, fileSize);

    // テクスチャをGPUに転送
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glBindTexture(GL_TEXTURE_2D, texID);
//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 256, 256, 0, GL_RGB, GL_UNSIGNED_BYTE, textureBuffer);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, textureBuffer);

    // テクスチャの設定
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    // テクスチャのアンバインド
    delete[] textureBuffer;
    glBindTexture(GL_TEXTURE_2D, 0);

    return texID;
}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);


    /* Create image texture */
//    string filename = "/Users/ashiya/git/cmake_example/data/cmake.png.bin";
//    string filename = "cat.raw";
    string filename = "cmake.png.bin";
    GLuint texID;

    GLuint programId = createShader();
    texID = loadTexture(filename,640,480);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClearColor(0.2f, 0.2f, 0.2f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearDepth(1.0);

        // 頂点データ
        float vertex_position[] = {
            0.5f, 0.5f,
            -0.5f, 0.5f,
            -0.5f, -0.5f,
            0.5f, -0.5f
        };

        const GLfloat vertex_uv[] = {
            1, 0,
            0, 0,
            0, 1,
            1, 1,
        };

        // 何番目のattribute変数か
        int positionLocation = glGetAttribLocation(programId, "position");
        int uvLocation = glGetAttribLocation(programId, "uv");
        int textureLocation = glGetUniformLocation(programId, "texture");

        // attribute属性を有効にする
        glEnableVertexAttribArray(positionLocation);
        glEnableVertexAttribArray(uvLocation);

        // uniform属性を設定する
        glUniform1i(textureLocation, 0);

        // attribute属性を登録
        glVertexAttribPointer(positionLocation, 2, GL_FLOAT, false, 0, vertex_position);
        glVertexAttribPointer(uvLocation, 2, GL_FLOAT, false, 0, vertex_uv);

        // モデルの描画
        glBindTexture(GL_TEXTURE_2D, texID);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}