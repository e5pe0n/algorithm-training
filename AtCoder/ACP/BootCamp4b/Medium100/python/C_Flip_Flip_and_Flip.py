N, M = list(map(int, input().split()))
if N > M:
    N, M = M, N
res = 0
if M == 1:
    res = 1
elif N == 2 or M == 2:
    res = 0
elif N == 1:
    res = M - 2
else:
    res = (N - 2) * (M - 2)
print(res)
