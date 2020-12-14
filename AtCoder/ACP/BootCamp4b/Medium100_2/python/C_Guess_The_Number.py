N, M = map(int, input().split())
SC = [list(map(int, input().split())) for _ in range(M)]
cnt = [0] * N
n = [0] * N
res = 0
for s, c in SC:
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
        res += n[i] * (10 ** (N - 1 - i))
print(res)
