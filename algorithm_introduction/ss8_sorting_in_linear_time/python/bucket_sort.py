from typing import List
from array import array


def insertion_sort(A: array):
    size = len(A)
    if size <= 0:
        return
    for i in range(1, size):
        j = i - 1
        key = A[i]
        while j >= 0 and A[j] > key:
            A[j + 1] = A[j]
            j -= 1
        A[j + 1] = key


def bucket_sort(A: array):
    size = len(A)
    B = [array('f') for _ in range(size)]
    for i in range(size):
        B[int(size * A[i])].append(A[i])
    for b in B:
        insertion_sort(b)
    idx = 0
    for b in B:
        for el in b:
            A[idx] = el
            idx += 1


def main():
    X = array('f', [.78, .17, .39, .26, .72, .94, .21, .12, .23, .68])

    print('# X')
    print(f'before: {X}')
    bucket_sort(X)
    print(f'after: {X}')


if __name__ == '__main__':
    main()
