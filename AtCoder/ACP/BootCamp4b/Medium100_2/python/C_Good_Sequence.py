from collections import Counter
N = int(input())
A = Counter(list(map(int, input().split())))
res = 0
for k, v in A.most_common():
    if k < v:
        res += v - k
    elif k > v:
        res += v
print(res)
