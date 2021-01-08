N = int(input())
XY = sorted([list(map(int, input().split())) for _ in range(N)])
res = N
for i in range(N - 1):
    for j in range(i + 1, N):
        p = XY[j][0] - XY[i][0]
        q = XY[j][1] - XY[i][1]
        cnt = 0
        used = [False] * N
        while True:
            idx = 0
            while idx < N:
                if not used[idx]:
                    break
                idx += 1
            if idx >= N:
                break
            cnt += 1
            x = XY[idx][0]
            y = XY[idx][1]
            used[idx] = True
            for k in range(idx + 1, N):
                if not used[k] and x + p == XY[k][0] and y + q == XY[k][1]:
                    used[k] = True
                    x += p
                    y += q
        res = min(res, cnt)
print(res)
