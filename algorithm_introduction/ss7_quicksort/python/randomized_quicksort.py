from array import array
import random


def partition(A: array, p: int, r: int):
    x = A[r]
    i = p - 1
    for j in range(p, r):
        if A[j] <= x:
            i += 1
            A[i], A[j] = A[j], A[i]
    A[i + 1], A[r] = A[r], A[i + 1]
    return i + 1


def randomized_partition(A: array, p: int, r: int):
    i = int(random.uniform(p, r + 1))
    A[i], A[r] = A[r], A[i]
    return partition(A, p, r)


def randomized_quicksort(A: array, p: int, r: int):
    if p < r:
        q = randomized_partition(A, p, r)
        randomized_quicksort(A, p, q - 1)
        randomized_quicksort(A, q + 1, r)


def main():
    cases = {
        'A': array('I', [2, 8, 7, 1, 3, 5, 6, 4]),
        'B': array('I', [2, 8, 7, 1, 3, 5, 6, 4, 9]),
    }

    for k, v in cases.items():
        print(f'# {k}')
        print(f'before: {v}')
        randomized_quicksort(v, 0, len(v) - 1)
        print(f'after: {v}')


if __name__ == '__main__':
    main()
