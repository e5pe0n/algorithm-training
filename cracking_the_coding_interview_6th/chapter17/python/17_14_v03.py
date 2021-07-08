from typing import List


def find_smallest_kth_nums(v: List[int], k: int) -> List[int]:
    v = v[:]
    if len(v) <= k:
        return v
    left, right = 0, len(v)
    cnt = 0
    while cnt != k:
        mid = (left + right) // 2
        pivot = v[mid]
        v[left], v[mid] = v[mid], v[left]
        last_less = left - 1
        for i in range(left, right):
            if v[i] < pivot:
                last_less += 1
                v[i], v[last_less] = v[last_less], v[i]
        if last_less + 1 <= k:
            cnt += last_less + 1 - left
            left = last_less + 1
        else:
            if right == last_less + 1:
                right -= 1
            else:
                right = last_less + 1
    return v[:k]


def ns(f):
    return next(f).strip()


def solve(fp: str):
    print(f"# {fp}")
    with open(fp) as f:
        n, k = map(int, ns(f).split())
        v = list(map(int, ns(f).split()))
    res = find_smallest_kth_nums(v, k)
    print(sorted(res))
    print()


solve("../testcases/17_14/01.txt")
solve("../testcases/17_14/02.txt")
solve("../testcases/17_14/03.txt")
