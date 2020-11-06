def ns(f):
    return next(f).strip()


with open("../testset/binary_indexed_tree/test1.txt", 'r') as f:
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


for i in range(N):
    _add(i + 1, A[i])

print(_sum(7))  # 35
print(_sum(4))  # 24
print(_sum(1))  # 5
