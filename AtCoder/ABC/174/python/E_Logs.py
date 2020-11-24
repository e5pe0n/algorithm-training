from math import ceil


N, K = map(int, input().split())
A = list(map(int, input().split()))

ub = max(A)
lb = 0
for i in range(100):
    md = (ub + lb) / 2
    t = sum([int(ceil(a / md)) - 1 for a in A])
    if t <= K:
        ub = md
    else:
        lb = md
print(int(ceil(ub)))
