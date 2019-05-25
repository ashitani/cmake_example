# pybind11

# 事前準備

pipでインストールした場合はfind_packageは効かないので、
cmakeで統一する場合は素直にpybind11もcmakeでインストール
したほうがよいかも。ここの例ではcmakeインストールのものを使っています。

なお、CMakeLists.txtに
```
find_package(python REQUIRED)
```
を足しておくと、システムではなく現在のパスでのpythonのバージョンに
合わせたライブラリが生成されます。


# pybindのビルドとインストール

```
mkdir build
cd build
cmake ..
make
sudo make install
```

# 使用例

```
mkdir build
cd build
cmake ..
make
cp ../test.py .
python test.py
```
