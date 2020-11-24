N, D = map(int, input().split())
C = [list(map(int, input().split())) for _ in range(N)]
res = 0
for c in C:
    if (c[0] * c[0] + c[1] * c[1]) ** 0.5 <= D:
        res += 1
print(res)
