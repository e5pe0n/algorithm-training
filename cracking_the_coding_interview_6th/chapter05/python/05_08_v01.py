from typing import List
from bitint import Int


def Int8(value: int) -> Int:
    return Int(value, 8)


def draw_line(screen: List[Int], w: int, x1: int, x2: int, y: int) -> None:
    _x1 = x1 // 8
    _x2 = x2 // 8
    left_mask = Int8(f"{(1 << (8 - (x1 % 8))) - 1:08b}")
    right_mask = ~Int8(0) << ((8 - (x2 + 1) % 8) % 8)
    mid_mask = ~Int8(0)
    if _x1 == _x2:
        screen[w * y + _x1] |= left_mask & right_mask
    else:
        screen[w * y + _x1] |= left_mask
        for j in range(_x1 + 1, _x2):
            screen[w * y + j] |= mid_mask
        screen[w * y + _x2] |= right_mask


def ns(f):
    return next(f).strip()


def solve(fp: str) -> None:
    print(f"# {fp}")
    with open(fp) as f:
        length, w, x1, x2, y = map(int, ns(f).split())
    screen = [Int8(0)] * length
    draw_line(screen, w, x1, x2, y)
    print(
        '\n'.join([' '.join(
            list(map(lambda x: f"{x:08b}", screen[y:y + w]))) for y in range(0, length, w)]))
    print()


solve("../testcases/05_08/01.txt")
solve("../testcases/05_08/02.txt")
solve("../testcases/05_08/03.txt")
solve("../testcases/05_08/04.txt")

# # ../testcases/05_08/01.txt
# 00000000 00000000 00000000
# 00000000 01111100 00000000
# 00000000 00000000 00000000

# # ../testcases/05_08/02.txt
# 00000000 00000000 00000000
# 00000000 11111111 00000000
# 00000000 00000000 00000000

# # ../testcases/05_08/03.txt
# 00000000 00000000 00000000
# 00011111 11111111 11111110
# 00000000 00000000 00000000

# # ../testcases/05_08/04.txt
# 00000000 00000000 00000000
# 00000000 00000000 00000000
# 11111111 11111111 11111111
