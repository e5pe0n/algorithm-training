MOD = 10 ** 9 + 7
N, K = list(map(int, input().split()))
A = list(map(int, input().split()))
res = 0
for i in range(N - 1):
    cnt = 0
    _cnt = 0
    for j in range(i + 1, N):
        if A[i] < A[j]:
            cnt += 1
        elif A[i] > A[j]:
            _cnt += 1
    res += (cnt * (K - 1) * K // 2 + _cnt * K * (K + 1) // 2) % MOD
print(res % MOD)
