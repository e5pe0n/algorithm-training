from array import array
import random


def partition(A: array, p: int, r: int) -> int:
    k = A[r]
    i = p - 1
    for j in range(p, r):
        if A[j] <= k:
            i += 1
            A[i], A[j] = A[j], A[i]
    A[i + 1], A[r] = A[r], A[i + 1]
    return i + 1


def randomized_partition(A: array, p: int, r: int) -> int:
    i = int(random.uniform(p, r))
    A[i], A[r] = A[r], A[i]
    return partition(A, p, r)


def randomized_select(A: array, p: int, r: int, i: int) -> int:
    if p == r:
        return A[r]
    q = randomized_partition(A, p, r)
    k = q - p + 1
    if i == k:
        return A[q]
    elif i < k:
        return randomized_select(A, p, q - 1, i)
    else:
        return randomized_select(A, q + 1, r, i - k)


def main():
    cases = {
        'X': array('I', [3, 2, 9, 0, 7, 5, 4, 8, 6, 1]),
        'Y': array('I', [3, 2, 9, 0, 7, 5, 4, 8, 6]),
    }

    for k, v in cases.items():
        print(f'# {k}: {v}')
        for i in (1, 3, 9):
            ans = randomized_select(v, 0, len(v) - 1, i)
            print(f'i: {i}, answer: {ans}')
        print()


if __name__ == '__main__':
    main()
