N, C, K = map(int, input().split())
T = sorted([int(input()) for _ in range(N)])

t = 0
cnt = 0
res = 0
for i in range(N):
    if T[i] > t:
        res += 1
        cnt = 0
        t = T[i] + K
    cnt += 1
    if cnt > C:
        res += 1
        cnt = 1
        t = T[i] + K
print(res)
