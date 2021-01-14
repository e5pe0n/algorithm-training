N = int(input())

res = N
for i in range(N + 1):
    x = 0
    t = i
    while t > 0:
        x += t % 6
        t //= 6
    t = N - i
    while t > 0:
        x += t % 9
        t //= 9
    res = min(res, x)
print(res)
