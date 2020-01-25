from array import array
from typing import List


def counting_sort(A: List[array], B: List[array], k: int, idx: int):
    C = array('I', [0 for _ in range(k + 1)])
    for arr in A:
        C[arr[idx]] += 1
    for i in range(len(C) - 1):
        C[i + 1] += C[i]
    for arr in A[::-1]:
        B[C[arr[idx]] - 1] = arr
        C[arr[idx]] -= 1


def radix_sort(A: List[array], B: List[array], k: int):
    for i in range(len(A[0]) - 1, -1, -1):
        counting_sort(A, B, k, i)
        A, B = B, A


def main():
    cases = {
        'X': {
            'org': [3297, 4576, 6575, 8394, 4363, 7202, 3551],
            'k': 9
        },
        'Y': {
            'org': [329, 457, 657, 839, 436, 720, 355],
            'k': 9
        },
    }

    for key, value in cases.items():
        print(f'# {key}')
        A = [list(str(x)) for x in value['org']]
        A = [array('I', [int(x) for x in lst]) for lst in A]

        B = [array('I', [0 for _ in range(len(A[0]))]) for _ in range(len(A))]

        print(f'before: {value["org"]}')
        radix_sort(A, B, value['k'])
        X = [int(''.join([str(s) for s in list(x)])) for x in (A, B)[len(A[0]) % 2]]
        print(f'after: {X}\n')


if __name__ == '__main__':
    main()
