def ns(f):
    return next(f).strip()


with open("../testset/subset_sum_problem_with_limitations/test1.txt", 'r') as f:
    N, K = map(int, ns(f).split())
    A = list(map(int, ns(f).split()))
    M = list(map(int, ns(f).split()))


dp = [0] + [-1] * K
for i in range(N):
    for j in range(K + 1):
        if dp[j] >= 0:
            dp[j] = M[i]
        elif j < A[i] or dp[j - A[i]] < 0:
            dp[j] = -1
        else:
            dp[j] = dp[j - A[i]] - 1
if dp[K] >= 0:
    print("Yes")
else:
    print("No")
