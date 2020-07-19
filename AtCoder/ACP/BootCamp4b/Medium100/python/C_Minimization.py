N, K = list(map(int, input().split()))
A = list(map(int, input().split()))
M = N - K
res = 1
if M > 0:
    res += M // (K - 1)
    if M % (K - 1) > 0:
        res += 1
print(res)
