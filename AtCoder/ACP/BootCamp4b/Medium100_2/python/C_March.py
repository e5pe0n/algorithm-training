from collections import Counter
from itertools import permutations
N = int(input())
S = Counter([input()[0] for _ in range(N)])
T = "MARCH"
B = [0, 0, 1, 1, 1]

res = 0
for p in set(permutations(B)):
    t = 1
    for i in range(5):
        if p[i]:
            t *= S[T[i]]
    res += t
print(res)
