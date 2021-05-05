def longest_1_sequence_len(n: int) -> int:
    prev_cnt, curr_cnt = 0, 0
    found_0 = False
    res = 0
    while n > 0:
        if not (n & 1):
            res = max(res, prev_cnt + curr_cnt + 1)
            prev_cnt, curr_cnt = curr_cnt, prev_cnt
            curr_cnt = 0
            found_0 = True
        else:
            curr_cnt += 1
        n >>= 1
    res = max(res, prev_cnt + curr_cnt + int(found_0))
    return res


def ns(f):
    return next(f).strip()


def solve(fp: str) -> None:
    print(f"# {fp}")
    with open(fp) as f:
        n = int(ns(f))
    print(longest_1_sequence_len(n))
    print()


solve("../testcases/05_03/01.txt")
solve("../testcases/05_03/02.txt")
solve("../testcases/05_03/03.txt")
solve("../testcases/05_03/04.txt")
