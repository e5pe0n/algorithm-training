from math import cos, sin, acos, degrees, pi


T = float(input())
L, X, Y = map(float, input().split())


def vt(E):
    return L * 0.5 * cos(-2 * pi / T * E - pi / 2)


def wt(E):
    return L * 0.5 * sin(2 * pi / T * E - pi / 2) + L * 0.5


Z = 0
u = 0
Q = int(input())
ress = []
for _ in range(Q):
    E = int(input())
    v = vt(E)
    w = wt(E)
    diag = ((u - X)**2 + (v - Y)**2 + (w - Z)**2)**0.5
    res = degrees(acos(w / diag))
    ress.append(90 - res)

print('\n'.join(map(lambda x: f"{x:.8f}", ress)))
