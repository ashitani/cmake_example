import cv2
import sys
import numpy as np

# image file to GL_RGB8UI

img = cv2.imread(sys.argv[1])
img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)

with open("img.bin", "wb") as fw:
    fw.write(bytearray(img))
