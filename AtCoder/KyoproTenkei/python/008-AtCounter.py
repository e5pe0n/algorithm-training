from collections import Counter


MOD = 10**9 + 7
A = "atcoder"

prv_chars = {A[i]: A[i - 1] for i in range(1, len(A))}

N = int(input())
S = input()


C = Counter()
for c in S:
    if c == 'a':
        C['a'] += 1
    elif c in A:
        C[c] = (C[c] + C[prv_chars[c]]) % MOD
print(C['r'])
