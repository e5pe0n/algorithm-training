import cmath
import matplotlib.pyplot as plt
import numpy as np
from typing import List


def recursive_fft(a: List[int]):
    n = len(a)
    if n == 1:
        return a
    wn = cmath.rect(1.0, 2 * cmath.pi / n)
    w = 1
    a0 = a[::2]
    a1 = a[1::2]
    y0 = recursive_fft(a0)
    y1 = recursive_fft(a1)
    y = [0] * n
    for k in range(n // 2):
        y[k] = y0[k] + w * y1[k]
        y[k + n // 2] = y0[k] - w * y1[k]
        w *= wn
    return y


def fact(n: int) -> int:
    if n <= 1:
        return 1
    ret = 1
    for i in range(2, n + 1):
        ret *= i
    return ret


def euler_sin(a: int, n: int) -> List[float]:
    ret = []
    for i in range(1, n + 1, 2):
        if ((i - 1) // 2) % 2 == 0:
            ret.append(1 / fact(i))
        else:
            ret.append(-(1 / fact(i)))
    return ret


def euler_cos(a: int, n: int) -> List[float]:
    ret = []
    for i in range(0, n + 1, 2):
        if (i // 2) % 2 == 0:
            ret.append(1 / fact(i))
        else:
            ret.append(-(1 / fact(i)))
    return ret


y = recursive_fft(euler_sin(1, 7))
N = 64
n = np.arange(N)
f1 = 1
A1 = 1
f = A1 * np.sin(2 * np.pi * f1 * n / N)
y_numpy = np.fft.fft(f)
plt.plot(f)

plt.
