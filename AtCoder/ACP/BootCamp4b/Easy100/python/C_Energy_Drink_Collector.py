N, M = list(map(int, input().split()))
V = [list(map(int, input().split())) for _ in range(N)]
V.sort()
res = 0
cnt = 0
for i in range(N):
    res += V[i][0] * V[i][1]
    cnt += V[i][1]
    if cnt > M:
        res -= V[i][0] * (cnt - M)
        break
print(res)
