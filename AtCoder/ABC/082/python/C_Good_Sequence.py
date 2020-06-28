from collections import Counter
N = int(input())
D = Counter([int(a) for a in input().split()])

cnt = 0
for k, v in D.items():
    if k < v:
        cnt += v - k
    elif v < k:
        cnt += v
print(cnt)
