from collections import Counter


N = int(input())
A = list(map(int, input().split()))

cnt = Counter(A)
t = 0
for c in cnt.values():
    t += c * (c - 1) // 2
for a in A:
    print(t - (cnt[a] - 1))
