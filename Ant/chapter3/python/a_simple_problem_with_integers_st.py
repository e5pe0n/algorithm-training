DATA_SIZE = (1 << 18) - 1


def ns(f):
    return next(f).strip()


data = [0] * DATA_SIZE
datb = [0] * DATA_SIZE


def _add(a, b, diff, k, left, right):
    if a <= left and right <= b:
        data[k] += diff
    elif left < b and a < right:
        datb[k] += (min(b, right) - max(a, left)) * diff
        _add(a, b, diff, k * 2 + 1, left, (left + right) // 2)
        _add(a, b, diff, k * 2 + 2, (left + right) // 2, right)


def _sum(a, b, k, left, right):
    if b <= left or right <= a:
        return 0
    elif a <= left and right <= b:
        return data[k] * (right - left) + datb[k]
    else:
        res = data[k] * (min(b, right) - max(a, left))
        res += _sum(a, b, k * 2 + 1, left, (left + right) // 2)
        res += _sum(a, b, k * 2 + 2, (left + right) // 2, right)
        return res


with open("../testset/a_simple_problem_with_integers/test2.txt", 'r') as f:
    N, C = map(int, ns(f).split())
    A = list(map(int, ns(f).split()))

    for i in range(N):
        _add(i, i + 1, A[i], 0, 0, N)

    for _ in range(C):
        T, *X = ns(f).split()
        if T == 'C':
            left, right, x = map(int, X)
            left -= 1
            right -= 1
            _add(left, right + 1, x, 0, 0, N)
        else:
            left, right = map(int, X)
            left -= 1
            right -= 1
            print(_sum(left, right + 1, 0, 0, N))
