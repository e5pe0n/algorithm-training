def ns(f):
    return next(f).strip()


with open("../testset/partial_sum/test2.txt", "r") as f:
    N = int(ns(f))
    A = list(map(int, ns(f).split()))
    K = int(ns(f))


def dfs(i, t):
    if i == N:
        return t == K
    return dfs(i + 1, t + A[i]) or dfs(i + 1, t)


if dfs(0, 0):
    print("Yes")
else:
    print("No")
