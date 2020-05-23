# open3d

# 事前準備

http://www.open3d.org/docs/release/compilation.html

jupyter 拡張が必要な場合はnpmが入っていないとダメ。ENABLE_JUPYTER is set to ONと標示されるのを確認しましょう。

```
brew install npm
git clone --recursive https://github.com/intel-isl/Open3D
cd Open3D
./util/scripts/install-deps-osx.sh
mkdir build
cmake ..
make
make install
```

# ビルドと実行

```
mkdir build
cd build
cmake ..
make
./main
```

