from typing import List


def insertion_sort(lst: List[int]):
    for i in range(1, len(lst)):
        key = lst[i]
        j = i - 1
        while j >= 0 and lst[j] > key:
            lst[j + 1] = lst[j]
            j -= 1
        lst[j + 1] = key


def main():
    cases = {
        'A': [3, 1, 5, 9, 4],
        'B': [3, 1, 5, 9, 4, 6],
    }
    for k, v in cases.items():
        print(k)
        print(f'before: {v}')
        insertion_sort(v)
        print(f'after: {v}\n')


if __name__ == '__main__':
    main()
