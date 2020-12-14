from collections import Counter


N = int(input())
A = list(map(int, input().split()))

cnt = Counter(A)
sm = 0
for k, v in cnt.most_common():
    sm += v * (v - 1) // 2
for a in A:
    print(sm - (cnt[a] - 1))
