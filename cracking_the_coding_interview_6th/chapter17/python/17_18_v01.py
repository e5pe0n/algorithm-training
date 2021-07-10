from typing import List, Tuple


def shortest_superseq(longer: List[int], shorter: List[int]) -> Tuple[int]:
    cnt = {k: 0 for k in shorter}
    left, right = 0, 0
    res = (0, len(longer))
    unique_nums = 0
    found = False
    while right < len(longer):
        while right < len(longer) and unique_nums < len(shorter):
            if longer[right] in cnt:
                if cnt[longer[right]] == 0:
                    unique_nums += 1
                cnt[longer[right]] += 1
            right += 1
        found |= unique_nums >= len(shorter)
        while unique_nums >= len(shorter):
            if longer[left] in cnt:
                cnt[longer[left]] -= 1
                if cnt[longer[left]] == 0:
                    unique_nums -= 1
            left += 1
        if right - left < res[1] - res[0]:
            res = (left - 1, right - 1)
    return res if found else (-1, -1)


def ns(f):
    return next(f).strip()


def solve(fp: str):
    print(f"# {fp}")
    with open(fp) as f:
        _, _ = map(int, ns(f).split())
        longer = list(map(int, ns(f).split()))
        shorter = list(map(int, ns(f).split()))
    print(shortest_superseq(longer, shorter))
    print()


solve("../testcases/17_18/01.txt")
solve("../testcases/17_18/02.txt")
solve("../testcases/17_18/03.txt")

# # ../testcases/17_18/01.txt
# (7, 10)

# # ../testcases/17_18/02.txt
# (318, 331)

# # ../testcases/17_18/03.txt
# (-1, -1)
