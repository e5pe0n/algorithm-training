from array import array


def _insertion_sort(A: array, p: int, r: int):
    # r is in range.

    for i in range(p + 1, r + 1):
        j = i - 1
        k = A[i]
        while j >= 0 and A[j] > k:
            A[j + 1] = A[j]
            j -= 1
        A[j + 1] = k


def _partition(A: array, p: int, r: int, x: int) -> int:
    i = p - 1
    for j in range(p, r + 1):
        if A[j] < x:
            i += 1
            A[i], A[j] = A[j], A[i]
    return i + 1


def _get_median(A: array, p: int, r: int) -> int:
    # r is in range.

    m = (r - p) // 2
    return A[p + m]


def _select(A: array, p: int, r: int, z: int) -> int:
    # Find z-th least value.
    # Be aware that z starts from 0.
    # r is in range.

    if p == r:
        return A[p]

    medians = array('I', [])
    q = (r - p + 1) // 5
    s = (r - p + 1) % 5

    for i in range(q):
        l = p + 5 * i
        _insertion_sort(A, l, l + 4)
        medians.append(_get_median(A, l, l + 4))

    if s > 0:
        _insertion_sort(A, r - s + 1, r)
        medians.append(_get_median(A, r - s + 1, r))

    x = _select(medians, 0, len(medians) - 1, (len(medians) - 1) // 2)
    k = _partition(A, p, r, x) - p
    if k == z:
        return x
    elif z < k:
        return _select(A, p, p + k - 1, z)
    else:
        return _select(A, p + k + 1, r, z - k - 1)


def main():
    X = array('I', [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 17, 18,
                    19, 13, 14, 15, 16, 20, 21, 25, 26, 27, 28, 22, 23, 24])

    print(f'X: {X}')
    for i in (0, 6, 10, 27):
        print(f'{i}-th least value: {_select(X, 0, len(X) - 1, i)}')


if __name__ == '__main__':
    main()
