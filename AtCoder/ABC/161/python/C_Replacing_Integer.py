N, K = map(int, input().split())
if N % K == 0:
    res = 0
else:
    res = min(N % K, K - N % K)
print(res)
