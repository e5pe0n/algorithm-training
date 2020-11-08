from bisect import bisect_left, bisect
from math import ceil


B = 1000


def ns(f):
    return next(f).strip()


with open("../testset/k_th_number/test1.txt", 'r') as f:
    N, M = map(int, ns(f).split())
    A = list(map(int, ns(f).split()))
    Q = [list(map(int, ns(f).split())) for _ in range(M)]


bucket = [sorted(A[i:i + B]) for i in range(0, N, B)]
_A = sorted(A)


for q in Q:
    # find k-th num in [left, right)
    left, right, k = q
    left -= 1   # modify left for 0-indexed. (right = (right - 1) + 1: 0-indexed)

    lb = -1
    ub = N - 1
    while ub - lb > 1:
        md = (lb + ub) // 2
        x = _A[md]

        tl = left
        tr = right
        c = 0
        while tl < tr and tl % B != 0:
            if A[tl] <= x:
                c += 1
            tl += 1
        while tl < tr and tr % B != 0:
            tr -= 1
            if A[tr] <= x:
                c += 1
        while tl < tr:
            b = tl // B
            c += bisect(bucket[b], x) - bisect_left(bucket[b], x)
            tl += B
        if c >= k:
            ub = md
        else:
            lb = md
    print(_A[ub])
