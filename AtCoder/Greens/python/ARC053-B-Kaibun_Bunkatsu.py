from collections import Counter
S = input()
C = Counter()
for s in S:
    C[s] += 1
odd, even = 0, 0
for v in C.values():
    odd += v % 2
    even += v // 2
if odd == 0:
    res = len(S)
else:
    res = 1 + even // odd * 2
print(res)
