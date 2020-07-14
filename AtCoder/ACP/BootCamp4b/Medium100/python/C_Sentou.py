N, T = list(map(int, input().split()))
_T = list(map(int, input().split()))
res = 0
for i in range(N - 1):
    res += min(T, _T[i + 1] - _T[i])
print(res + T)
