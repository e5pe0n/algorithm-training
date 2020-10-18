N, K = map(int, input().split())

ans = 0
for i in range(K + 1, N + 1):
    p = N // i
    q = i - K
    ans += p * q + max(0, (N - (p * i + K) + int(K != 0)))
print(ans)
