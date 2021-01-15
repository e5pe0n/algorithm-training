N, K = map(int, input().split())
res = 0
for b in range(K + 1, N + 1):
    p = N // b
    q = b - K
    res += p * q + max(0, N - (p * b + K) + int(K != 0))
print(res)
