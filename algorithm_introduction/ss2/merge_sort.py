from typing import List


INF = 1_000_000_000


def merge(lst: List[int], p: int, q: int, r: int):
    n1 = q - p + 1
    n2 = r - q

    left = [lst[p + i] for i in range(n1)]
    right = [lst[q + i + 1] for i in range(n2)]

    left.append(INF)
    right.append(INF)

    i = 0
    j = 0
    for k in range(p, r + 1):
        if left[i] <= right[j]:
            lst[k] = left[i]
            i += 1
        else:
            lst[k] = right[j]
            j += 1


def merge_sort(lst: List[int], p: int, r: int):
    if p < r:
        q = (p + r) // 2

        merge_sort(lst, p, q)
        merge_sort(lst, q + 1, r)
        merge(lst, p, q, r)


def main():
    cases = {
        'A': [13, 11, 15, 19, 14],
        'B': [13, 11, 15, 19, 14, 16],
    }

    for k, v in cases.items():
        print(k)
        print(f'before: {v}')
        merge_sort(v, 0, len(v) - 1)
        print(f'after: {v}\n')


if __name__ == '__main__':
    main()
