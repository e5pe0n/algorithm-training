# AC: 476 ms
N, K = map(int, input().split())

cnt = [0] * (N + 1)
for i in range(2, N + 1):
    if cnt[i] != 0:
        continue
    for j in range(i, N + 1, i):
        cnt[j] += 1
res = 0
for c in cnt:
    if c >= K:
        res += 1
print(res)
