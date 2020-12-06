K, N = map(int, input().split())
A = list(map(int, input().split()))
max_d = 0
res = 0
for i in range(N):
    d = (A[(i + 1) % N] - A[i] + K) % K
    res += d
    if max_d < d:
        max_d = d
res -= max_d
print(res)
