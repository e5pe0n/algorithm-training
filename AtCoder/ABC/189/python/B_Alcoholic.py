N, X = map(int, input().split())
VP = [list(map(int, input().split())) for _ in range(N)]

X *= 100
for i, (v, p) in enumerate(VP):
    X -= v * p
    if X < 0:
        print(i + 1)
        exit()
print(-1)
