from bitint import Int


def Int8(value: int) -> Int:
    return Int(value, 8)


n = Int8(1) << 7
print(f"{n:08b}")
n - 1
