from bitint import Int, Int32


def pairwise_swap(n: Int) -> Int:
    k = (n.bit + 4 - 1) // 4
    even_mask = Int("1010" * k, n.bit + 5)
    odd_mask = Int("0101" * k, n.bit + 5)
    res = ((n & even_mask) >> 1) | ((n & odd_mask) << 1)
    return Int(f"{res:0{n.bit}b}", n.bit)


def ns(f):
    return next(f).strip()


def solve(fp: str) -> None:
    print(f"# {fp}")
    with open(fp) as f:
        n = Int32(int(ns(f)))
    print(f"{n:032b} -> {pairwise_swap(n):032b}")
    print()


solve("../testcases/05_07/01.txt")
solve("../testcases/05_07/02.txt")

# # ../testcases/05_07/01.txt
# 00111011000010010010011000011000 -> 00110111000001100001100100100100

# # ../testcases/05_07/02.txt
# 00011101100001001001001100001100 -> 00101110010010000110001100001100
