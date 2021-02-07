from math import ceil
X, Y, R = map(float, input().split())
left = int(ceil(X - R))
right = int(X + R)

res = 0
for x in range(left, right + 1):
    top = int((R**2 - (x - X)**2)**0.5 + Y)
    bottom = int(ceil(Y - (R**2 - (x - X)**2)**0.5))
    res += (top - bottom) + 1
print(res)
