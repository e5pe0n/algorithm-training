from bisect import bisect_left


def ns(f):
    return next(f).strip()


with open("../testset/lower_bound/test3.txt", 'r') as f:
    n, k = map(int, ns(f).split())
    a = list(map(int, ns(f).split()))


ans = bisect_left(a, k)
print(ans)
