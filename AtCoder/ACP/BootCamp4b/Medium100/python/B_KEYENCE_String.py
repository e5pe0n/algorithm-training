import sys
S = input()
_S = 'keyence'
_N = len(_S)
for i in range(_N + 1):
    if _S[:i] == S[:i] and _S[i:] == S[len(S) - _N + i:]:
        print('YES')
        sys.exit()
print('NO')
