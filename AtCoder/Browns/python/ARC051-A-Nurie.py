Y, N = "YES", "NO"

x1, y1, r = map(int, input().split())
x2, y2, x3, y3 = map(int, input().split())
d1 = (x2 - x1) ** 2 + (y2 - y1) ** 2 - r ** 2
d2 = (x2 - x1) ** 2 + (y3 - y1) ** 2 - r ** 2
d3 = (x3 - x1) ** 2 + (y2 - y1) ** 2 - r ** 2
d4 = (x3 - x1) ** 2 + (y3 - y1) ** 2 - r ** 2

if all(list(map(lambda x: x <= 0, (d1, d2, d3, d4)))):
    red, blue = Y, N
elif x2 <= x1 - r and x1 + r <= x3 and y2 <= y1 - r and y1 + r <= y3:
    red, blue = N, Y
else:
    red, blue = Y, Y
print(red)
print(blue)
