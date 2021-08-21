from itertools import permutations
S, K = input().split()
K = int(K)
S = sorted(list(S))
print(''.join(sorted(list(set(list(permutations(S)))))[K - 1]))
