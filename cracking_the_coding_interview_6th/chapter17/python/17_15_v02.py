from typing import FrozenSet, Iterable


def can_build_word(s: str, is_org_word: str, st: FrozenSet[str]) -> bool:
    if s in st and not is_org_word:
        return True
    for i in range(1, len(s)):
        left = s[:i]
        right = s[i:]
        if left in st and can_build_word(right, False, st):
            return True
    return False


def longest_composite_word(v: Iterable[int]) -> str:
    st = set(v)
    v = sorted(v, key=lambda x: len(x), reverse=True)
    for s in v:
        if can_build_word(s, True, st):
            return s
    return ""


def ns(f):
    return next(f).strip()


def solve(fp: str):
    print(f"# {fp}")
    with open(fp) as f:
        _ = int(ns(f))
        v = ns(f).split()
    print(longest_composite_word(v))
    print()


solve("../testcases/17_15/01.txt")
solve("../testcases/17_15/03.txt")
solve("../testcases/17_15/03.txt")
solve("../testcases/17_15/04.txt")
solve("../testcases/17_15/05.txt")

# # ../testcases/17_15/01.txt
# dogwalker

# # ../testcases/17_15/03.txt
# dogcatwalkerwalknanabanana

# # ../testcases/17_15/03.txt
# dogcatwalkerwalknanabanana

# # ../testcases/17_15/04.txt
# timeline

# # ../testcases/17_15/05.txt
# informationtechnology
