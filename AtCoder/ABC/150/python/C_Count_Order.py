from itertools import permutations
N = int(input())
P = tuple(map(int, input().split()))
Q = tuple(map(int, input().split()))
A = list(range(1, N + 1))

perm = sorted(list(set(list(permutations(A)))))
for i, p in enumerate(perm, 1):
    if p == P:
        a = i
    if p == Q:
        b = i
print(abs(a - b))
