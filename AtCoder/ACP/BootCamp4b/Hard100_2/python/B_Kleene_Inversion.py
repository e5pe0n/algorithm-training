MOD = 10**9 + 7
N, K = map(int, input().split())
A = list(map(int, input().split()))
res = 0
for i in range(N - 1):
    for j in range(i + 1, N):
        if A[i] > A[j]:
            res = (res + K * (K + 1) // 2) % MOD
        elif A[i] < A[j]:
            res = (res + (K - 1) * K // 2) % MOD
print(res)
