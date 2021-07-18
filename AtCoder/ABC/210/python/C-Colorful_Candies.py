from collections import Counter
N, K = map(int, input().split())
C = list(map(int, input().split()))

cnt = Counter(C[:K])
t = len(set(C[:K]))
res = t
for i in range(K, N):
    cnt[C[i - K]] -= 1
    if cnt[C[i - K]] == 0:
        t -= 1
    if cnt[C[i]] == 0:
        t += 1
    cnt[C[i]] += 1
    res = max(res, t)
print(res)
