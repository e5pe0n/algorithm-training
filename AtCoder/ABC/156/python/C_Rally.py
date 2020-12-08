N = int(input())
X = list(map(int, input().split()))

res = float('inf')
for x in range(101):
    t = 0
    for xi in X:
        t += (xi - x) ** 2
    res = min(res, t)
print(res)
