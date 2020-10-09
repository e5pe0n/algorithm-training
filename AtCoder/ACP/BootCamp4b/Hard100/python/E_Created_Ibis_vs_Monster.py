INF = 1_000_000_000


H, N = [int(x) for x in input().split()]
d = [0] + [INF] * H
for _ in range(N):
    a, b = [int(x) for x in input().split()]
    for j in range(1, H + 1):
        d[min(H, j + a)] = min(d[min(H, j + a)], d[j] + b)
print(d[H])
