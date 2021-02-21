D = [0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
N = int(input())
H = [[False] * 32 for _ in range(13)]
for _ in range(N):
    m, d = map(int, input().split('/'))
    H[m][d] = True
d = 0
cnt = 0
stock = 0
res = 0
for i in range(1, 13):
    for j in range(1, D[i] + 1):
        if d == 0 or d == 6:
            cnt += 1
            if H[i][j]:
                stock += 1
        else:
            if H[i][j]:
                cnt += 1
            elif stock > 0:
                stock -= 1
                cnt += 1
            else:
                cnt = 0
        d = (d + 1) % 7
        res = max(res, cnt)
print(res)
