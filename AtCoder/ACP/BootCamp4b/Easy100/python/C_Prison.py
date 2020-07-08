N, M = list(map(int, input().split()))
L, R, flg = 1, N, True
for i in range(M):
    _L, _R = list(map(int, input().split()))
    if L <= _L and _R <= R:
        L = _L
        R = _R
    elif _L <= L and R <= _R:
        continue
    elif L <= _L <= R <= _R:
        L = _L
    elif _L <= L <= _R <= R:
        R = _R
    else:
        flg = False
if flg:
    print(R - L + 1)
else:
    print(0)
