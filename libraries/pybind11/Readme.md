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
合わせたライブラリが生成されます。pyenvなどを使っている場合は記載。

# pybind11のビルド

```
pip install pytest
git clone https://github.com/pybind/pybind11.git
cd pybind11
mkdir build
cmake ..
make
make install
```

# addmdl

int同士の足し算です。

# numpytest

eigenで作成したones行列をnumpyに変換します。
tupleも返せるか確認します。

# 使用例

```
mkdir build
cd build
cmake ..
make
cp ../test.py .
python test.py
```
