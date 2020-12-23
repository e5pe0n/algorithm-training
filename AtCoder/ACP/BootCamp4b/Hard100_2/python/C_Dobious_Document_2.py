_S = input()
T = input()

_S = _S[::-1]
T = T[::-1]
N = len(_S)
M = len(T)
res = []
for i in range(N - M + 1):
    f = True
    for j in range(M):
        if _S[i + j] != T[j] and _S[i + j] != '?':
            f = False
    if f:
        res += list(T) + list(_S[i + M:])
        res = ''.join(list(map(lambda x: 'a' if x == '?' else x, res[::-1])))
        print(res)
        exit()
    res.append(_S[i])
print("UNRESTORABLE")
