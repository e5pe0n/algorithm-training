def ns(f):
    return next(f).strip()


with open("../testset/longest_increasing_subsequence/test1.txt", 'r') as f:
    N = int(ns(f))
    A = list(map(int, ns(f).split()))


dp = [0] * N
res = 0
for i in range(N):
    dp[i] = 1
    for j in range(0, i):
        if A[j] < A[i]:
            dp[i] = max(dp[i], dp[j] + 1)
    res = max(res, dp[i])
print(res)
