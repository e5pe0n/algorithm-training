from collections import Counter


N = int(input())
A = list(map(int, input().split()))
cnt1 = Counter()
cnt2 = Counter()
for i in range(N):
    cnt1[i + A[i]] += 1
    cnt2[i - A[i]] += 1

res = 0
for x in range(1, N):
    res += cnt1[x] * cnt2[x]
print(res)
