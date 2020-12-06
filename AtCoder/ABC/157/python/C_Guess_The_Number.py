N, M = map(int, input().split())
S = [list(map(int, input().split())) for _ in range(M)]

n = [0] * N
cnt = [0] * N
res = 0
for s, c in S:
    if N >= 2 and s == 1 and c == 0:
        res = -1
        break
    if cnt[s - 1] > 0 and n[s - 1] != c:
        res = -1
        break
    n[s - 1] = c
    cnt[s - 1] += 1
if res == 0:
    if N >= 2:
        n[0] = max(1, n[0])
    for i in range(N):
        res += n[i] * (10 ** (N - i - 1))
print(res)
