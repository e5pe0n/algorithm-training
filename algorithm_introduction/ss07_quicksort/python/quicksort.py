from array import array


def partition(A: array, p: int, r: int):
    x = A[r]
    i = p - 1
    for j in range(p, r):
        if A[j] <= x:
            i += 1
            A[i], A[j] = A[j], A[i]
    A[i + 1], A[r] = A[r], A[i + 1]
    return i + 1


def quicksort(A: array, p: int, r: int):
    if p < r:
        q = partition(A, p, r)
        quicksort(A, p, q - 1)
        quicksort(A, q + 1, r)


def main():
    cases = {
        'A': array('I', [2, 8, 7, 1, 3, 5, 6, 4]),
        'B': array('I', [2, 8, 7, 1, 3, 5, 6, 4, 9]),
    }

    for k, v in cases.items():
        print(f'# {k}')
        print(f'before: {v}')
        quicksort(v, 0, len(v) - 1)
        print(f'after: {v}\n')


if __name__ == '__main__':
    main()
