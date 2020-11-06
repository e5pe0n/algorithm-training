def ns(f):
    return next(f).strip()


with open("../testset/swap_num_of_bubble_sort/test1.txt", 'r') as f:
    N = int(ns(f))
    A = list(map(int, ns(f).split()))


B = [0] * (N + 1)


def _sum(i):
    s = 0
    while i > 0:
        s += B[i]
        i -= i & -i
    return s


def _add(i, diff):
    global B
    while i <= N:
        B[i] += diff
        i += i & -i


ans = 0
for i in range(N):
    ans += i - _sum(A[i])
    _add(A[i], 1)
print(ans)
