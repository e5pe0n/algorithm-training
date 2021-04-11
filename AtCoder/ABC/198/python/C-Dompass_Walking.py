from math import ceil
R, X, Y = map(int, input().split())

dst = (X*X + Y*Y)**0.5
print(int(ceil(dst / R)) + int(dst < R))
