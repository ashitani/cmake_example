# pybind11

# 事前準備

pipでインストールした場合はfind_packageは効かないので、
cmakeで統一する場合は素直にpybind11もcmakeでインストール
したほうがよいかも。ここの例ではcmakeインストールのものを使っている。

ただしその場合は当然ながらpybind11をインストールしたときのpythonと
結びついてしまう。デフォルトだとシステムのpythonを見に行くようなので、
pyenv等を使っている場合はそちらのパスを指定するとよい。

# pybindのビルドとインストール

```
mkdir build
cd build
cmake .. -DPYTHON_EXECUTABLE=`which python`
make
sudo make install
```

# pybindのビルドとインストール

```
mkdir build
cd build
cmake ..
make
python -c "import addmdl;print(addmdl.add(10,20))"
```
