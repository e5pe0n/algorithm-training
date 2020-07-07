import sys
from itertools import permutations
N = int(input())
P = tuple(map(int, input().split()))
Q = tuple(map(int, input().split()))

if P == Q:
    print(0)
    sys.exit()

perm = list(permutations(P))
perm.sort()
p, q = -1, -1
for i, pm in enumerate(perm):
    if pm == P:
        p = i
    if pm == Q:
        q = i
print(abs(p - q))
