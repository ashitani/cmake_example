# OpenCV

# 事前準備

find_packageは[こちら](https://qiita.com/osamu0329/items/bd3d1e50edf37c277fa9)にあるようなロジックでパッケージを探す。
find_packageが見つけられない場合は環境変数OpenCV_DIRをopencv/buildなどに設定するとOk。

# ビルドと実行

```
export OpenCV_DIR=~/git/opencv/build
mkdir build
cd build
cmake ..
make
./test
```

