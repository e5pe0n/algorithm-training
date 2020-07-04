from itertools import permutations

N = int(input())
K = int(input())
C = [int(input()) for _ in range(N)]

perm = list(permutations(C, K))
S = {int(''.join([str(s) for s in p])) for p in perm}
print(len(S))
