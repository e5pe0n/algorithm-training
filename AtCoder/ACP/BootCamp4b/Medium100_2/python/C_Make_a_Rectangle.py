from collections import Counter
N = int(input())
A = Counter(list(map(int, input().split())))

res = 0
max_a = 0
max_a2 = 0
for k, v in A.most_common():
    if v < 2:
        continue
    if v >= 4:
        res = max(res, k * k)
    if max_a <= k:
        max_a2 = max_a
        max_a = k
    elif max_a2 <= k:
        max_a2 = k
res = max(res, max_a * max_a2)
print(res)
