from collections import Counter
N = int(input())
cnt = Counter()
for _ in range(N):
    a = int(input())
    cnt[a] += 1
res = 0
for k, v in cnt.most_common():
    if v % 2 != 0:
        res += 1
print(res)
