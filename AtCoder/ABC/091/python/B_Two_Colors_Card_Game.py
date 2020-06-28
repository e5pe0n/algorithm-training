from collections import Counter
N = int(input())
B = Counter([input() for _ in range(N)])
M = int(input())
R = Counter([input() for _ in range(M)])
res = 0
for k, v in B.items():
    res = max(res, v - R[k])
print(res)
