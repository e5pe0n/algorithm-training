a, b, c, d = map(int, input().split())
res = max(a * c, a * d, b * c, b * d)
print(res)
