#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>

#include "imgui.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_sdl.h"

#include <GL/gl3w.h>
#include <SDL.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

using namespace std;

//---------------------------------------------------------------------

class ImageTexture {
 private:
  int width, height;
  unsigned char* my_image_data;
  GLuint my_opengl_texture;

 public:
  void setImage(string, int, int);
  void* getOpenglTexture();
  ImVec2 getSize();
};

void ImageTexture::setImage(string filename, int w, int h) {
  // load image
  width = w;
  height = h;
  my_image_data = stbi_load(filename.c_str(), &width, &height, NULL, 4);

  // Turn the RGBA pixel data into an OpenGL texture:
  glGenTextures(1, &my_opengl_texture);
  glBindTexture(GL_TEXTURE_2D, my_opengl_texture);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA,
               GL_UNSIGNED_BYTE, my_image_data);
}

void* ImageTexture::getOpenglTexture() { return (void*)(intptr_t)my_opengl_texture; }
ImVec2 ImageTexture::getSize() { return ImVec2(width, height); };

//---------------------------------------------------------------------

class SimpleGUI {
 private:
  SDL_Window* window;
  SDL_GLContext gl_context;
  ImGuiIO* io;

  // static contents
  ImVec4 clear_color;
  ImageTexture my_texture;

 public:
  SimpleGUI();
  void init();
  void initContents();
  bool handleEvent();
  void drawContents();
  void render();
  void exit();
};

SimpleGUI::SimpleGUI() {
  init();
  initContents();

  io = &ImGui::GetIO();
  (void)&io;
}

void SimpleGUI::init() {
  // Setup SDL
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER) !=
      0) {
    printf("Error: %s\n", SDL_GetError());
    exit();
  }

  const char* glsl_version = "#version 150";
  SDL_GL_SetAttribute(
      SDL_GL_CONTEXT_FLAGS,
      SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);  // Always required on Mac
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

  // Create window with graphics context
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
  SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
  SDL_WindowFlags window_flags = (SDL_WindowFlags)(
      SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
  // SDL_Window*
  window = SDL_CreateWindow("Simple ImGui Example", SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED, 1280, 720, window_flags);
  // SDL_GLContext
  gl_context = SDL_GL_CreateContext(window);
  SDL_GL_SetSwapInterval(1);  // Enable vsync

  bool err = gl3wInit() != 0;
  if (err) {
    fprintf(stderr, "Failed to initialize OpenGL loader!\n");
    exit();
  }

  // Setup Dear ImGui context
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();

  // Setup Dear ImGui style
  ImGui::StyleColorsDark();

  // Setup Platform/Renderer bindings
  ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
  ImGui_ImplOpenGL3_Init(glsl_version);
}

void SimpleGUI::render() {
  // Rendering
  ImGui::Render();
  SDL_GL_MakeCurrent(window, gl_context);
  glViewport(0, 0, (int)io->DisplaySize.x, (int)io->DisplaySize.y);
  glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
  glClear(GL_COLOR_BUFFER_BIT);
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
  SDL_GL_SwapWindow(window);
}

void SimpleGUI::exit() {
  // Cleanup
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplSDL2_Shutdown();
  ImGui::DestroyContext();

  SDL_GL_DeleteContext(gl_context);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void SimpleGUI::initContents() {
  clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

  // Image data
  my_texture.setImage("../../data/cmake.png", 640, 480);
}

void SimpleGUI::drawContents() {
  // Start the Dear ImGui frame
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplSDL2_NewFrame(window);
  ImGui::NewFrame();

  // Simple Gui

  ImGui::Begin("Imgae test");

  // -- copied from imgui.cpp document in the source code --
  ImGui::Image(my_texture.getOpenglTexture(),
               my_texture.getSize());

  ImGui::Text("Application average %.3f ms/frame (%.1f FPS)",
              1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
  ImGui::End();
}

bool SimpleGUI::handleEvent() {
  SDL_Event event;
  bool done = false;
  while (SDL_PollEvent(&event)) {
    ImGui_ImplSDL2_ProcessEvent(&event);
    if (event.type == SDL_QUIT) done = true;
    if (event.type == SDL_WINDOWEVENT &&
        event.window.event == SDL_WINDOWEVENT_CLOSE &&
        event.window.windowID == SDL_GetWindowID(window))
      done = true;
  }
  return done;
}

//---------------------------------------------------------------------

int main(int, char**) {
  SimpleGUI gui;

  // Main loop
  while (!gui.handleEvent()) {
    gui.drawContents();
    gui.render();
  }
  gui.exit();

  return 0;
}
