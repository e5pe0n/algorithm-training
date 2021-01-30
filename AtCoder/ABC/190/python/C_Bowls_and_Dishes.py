from collections import Counter
N, M = map(int, input().split())
AB = [list(map(lambda x: int(x) - 1, input().split())) for _ in range(M)]
K = int(input())
CD = [list(map(lambda x: int(x) - 1, input().split())) for _ in range(K)]

res = 0
for i in range(1 << K):
    t = 0
    cnt = Counter()
    for j in range(K):
        if i >> j & 1:
            cnt[CD[j][0]] += 1
        else:
            cnt[CD[j][1]] += 1
    for a, b in AB:
        if cnt[a] > 0 and cnt[b] > 0:
            t += 1
    res = max(res, t)
print(res)
