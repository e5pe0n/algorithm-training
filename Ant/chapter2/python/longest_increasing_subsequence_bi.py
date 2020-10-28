from bisect import bisect_left


INF = float('inf')


def ns(f):
    return next(f).strip()


with open("../testset/longest_increasing_subsequence/test2.txt", 'r') as f:
    N = int(ns(f))
    A = list(map(int, ns(f).split()))

dp = [INF] * N
for a in A:
    dp[bisect_left(dp, a)] = a
print(bisect_left(dp, INF))
