def cnt_2s_at_digit(n: int, d: int) -> int:
    power_of_10 = 10**d
    next_power_of_10 = power_of_10 * 10
    right = n % power_of_10

    round_down = n - n % next_power_of_10
    round_up = round_down + next_power_of_10

    digit = (n // power_of_10) % 10
    if digit < 2:
        return round_down // 10
    elif digit == 2:
        return round_down // 10 + right + 1
    else:
        return round_up // 10


def cnt_2s(n: int) -> int:
    cnt = 0
    for i in range(len(str(n))):
        cnt += cnt_2s_at_digit(n, i)
    return cnt


def ns(f):
    return next(f).strip()


def solve(fp: str):
    print(f"# {fp}")
    with open(fp) as f:
        n = int(ns(f))
    res = cnt_2s(n)
    print(res)
    print()


solve("../testcases/17_06/01.txt")
solve("../testcases/17_06/02.txt")
solve("../testcases/17_06/03.txt")


# # ../testcases/17_06/01.txt
# 9

# # ../testcases/17_06/02.txt
# 300

# # ../testcases/17_06/03.txt
# 4543901
