from collections import Counter


N, K = map(int, input().split())
A = list(map(int, input().split()))

cnt = Counter(A)
cnt = sorted(cnt.most_common(), key=lambda x: x[1])
i = 0
res = 0
k = len(cnt)
while k > K:
    res += cnt[i][1]
    i += 1
    k -= 1
print(res)
