N = int(input())
A = list(map(int, input().split()))
_A = [0] * (N + 1)
L = sum(A)
res = 1_000_000_000_000_000_000
for i in range(N - 1):
    _A[i + 1] = _A[i] + A[i]
    res = min(res, abs(_A[i + 1] - L + _A[i + 1]))
print(res)
