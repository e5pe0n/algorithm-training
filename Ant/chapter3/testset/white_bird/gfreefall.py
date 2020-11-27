import numpy as np
import matplotlib.pyplot as plt


G = 9.8

t = 0.0
h = 0.01

v = -40
theta = np.pi / 3.0
vx = v * np.cos(theta)
vy = v * np.sin(theta)
x, y = 0, 0

tlist = [t]
xlist = [x]
ylist = [y]

while x >= 0:
    t += h
    x += vx * h
    vy += G * h
    y -= vy * h
    tlist.append(t)
    xlist.append(x)
    ylist.append(y)
plt.plot(tlist, ylist)
plt.show()
