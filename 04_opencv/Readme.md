# OpenCV

# 事前準備

find_packageは[こちら](https://qiita.com/osamu0329/items/bd3d1e50edf37c277fa9)にあるようなロジックでパッケージを探す。

環境変数OpenCV_DIRをopencv/buildなどに設定するとOk。

# ビルドと実行

```
mkdir build
cd build
cmake ..
make
cp ../hello.png .
./test
```

