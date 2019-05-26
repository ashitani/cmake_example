import addmdl

print("1+2=", addmdl.add(1,2))

import numpytest
import numpy as np

a = numpytest.ones(2, 3)
print("2x3 ones")
print(a)

a,b = numpytest.oneses(2, 3, 1, 2)
print("2x3 ones")
print(a)
print("1x2 ones")
print(b)

print("3x2 ones")
m = numpytest.MyClass()
a=m.ones(3, 2)
print(a)