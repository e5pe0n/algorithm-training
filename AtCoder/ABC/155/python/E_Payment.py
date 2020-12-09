N = input()
_N = len(N)
ext = [1] + [0] * _N
jst = [0] * (_N + 1)
for i in range(1, _N + 1):
    n = int(N[i - 1])
    ext[i] = min(ext[i - 1] + 10 - (n + 1), jst[i - 1] + (n + 1))
    jst[i] = min(ext[i - 1] + 10 - n, jst[i - 1] + n)
print(jst[_N])
