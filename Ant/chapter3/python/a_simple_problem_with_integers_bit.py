def ns(f):
    return next(f).strip()


with open("../testset/a_simple_problem_with_integers/test2.txt", 'r') as f:
    N, Q = map(int, ns(f).split())
    A = list(map(int, ns(f).split()))
    C = [ns(f).split() for _ in range(Q)]


bit0 = [0] * (N + 1)
bit1 = [0] * (N + 1)


def _sum(b, i):
    s = 0
    while (i > 0):
        s += b[i]
        i -= i & -i
    return s


def _add(b, i, diff):
    while i <= N:
        b[i] += diff
        i += i & -i


for i in range(1, N + 1):
    _add(bit0, i, A[i - 1])
for i in range(Q):
    t, *c = C[i]
    if t == 'C':
        left, right, x = map(int, c)
        _add(bit0, left, -x * (left - 1))
        _add(bit1, left, x)
        _add(bit0, right + 1, x * right)
        _add(bit1, right + 1, -x)
    else:
        left, right = map(int, c)
        res = 0
        res += _sum(bit0, right) + _sum(bit1, right) * right
        res -= _sum(bit0, left - 1) + _sum(bit1, left - 1) * (left - 1)
        print(res)
