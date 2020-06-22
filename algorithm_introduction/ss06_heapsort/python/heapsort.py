from array import array


def parent(i):
    return (i - 1) >> 1


def left(i):
    return ((i + 1) << 1) - 1


def right(i):
    return (i + 1) << 1


def max_heapify(A, last_heap_idx, i):
    largest = i
    l = left(i)
    r = right(i)
    if l <= last_heap_idx and A[l] > A[i]:
        largest = l
    if r <= last_heap_idx and A[r] > A[largest]:
        largest = r
    if largest != i:
        A[i], A[largest] = A[largest], A[i]
        max_heapify(A, last_heap_idx, largest)


def build_max_heap(A):
    last_heap_idx = len(A) - 1
    for i in range((len(A) >> 1) - 1, -1, -1):
        max_heapify(A, last_heap_idx, i)


def heap_sort(A):
    build_max_heap(A)
    for i in range(len(A) - 1, 0, -1):
        A[0], A[i] = A[i], A[0]
        max_heapify(A, i - 1, 0)


def main():
    cases = {
        'A': array('I', [4, 1, 3, 2, 16, 9, 10, 14, 8, 7]),
        'B': array('I', [4, 1, 3, 2, 16, 9, 10, 14, 8]),
    }
    for k, v in cases.items():
        print(f'# {k}')
        print(f'before: {v}')
        heap_sort(v)
        print(f'after: {v}\n')


if __name__ == '__main__':
    main()
