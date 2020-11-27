from collections import Counter


N = int(input())
A = list(map(int, input().split()))
Q = int(input())
X = [list(map(int, input().split())) for _ in range(Q)]

cnt = Counter()
for a in A:
    cnt[a] += 1
res = sum(A)
for b, c in X:
    res += (c - b) * cnt[b]
    print(res)
    cnt[c] += cnt[b]
    cnt[b] = 0
