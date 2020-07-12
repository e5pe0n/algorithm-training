N = int(input())
A = list(map(int, input().split()))

_a = 1
res = 0
for i in range(N):
    res += _a * (A[i] % 2 + 1) * 3 ** (N - i - 1)
    if A[i] % 2 == 0:
        _a *= 2
print(res)
