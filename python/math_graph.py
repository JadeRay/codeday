#!/usr/bin/python

import matplotlib.pyplot as plt
import math as math
import numpy as np

def fun1(x):
	w = -(36*x - 36/math.e)**4
	z = 1.0/36 * math.e**w
	y = z - 3*x*np.log10(x) 
	return y
	
y = np.linspace(1, 0, 10000, endpoint=False)
x = fun1(y);
plt.xlim(0, 1.6)
plt.plot(x, y, color="red", linewidth=1.0)
plt.fill_between(x, y, 0, None, color="red")
plt.show()