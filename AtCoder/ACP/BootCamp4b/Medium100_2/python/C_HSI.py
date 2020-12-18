N, M = map(int, input().split())
_p = 2 ** M
res = (100 * (N - M) + 1900 * M) * _p
print(res)
