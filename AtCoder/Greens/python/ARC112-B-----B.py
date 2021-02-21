B, C = map(int, input().split())


def extract(_B, _C):
    n = _C // 2
    if _C % 2:
        return (-_B - n, -_B + n)
    else:
        if not _C:
            return (_B, _B)
        return (_B - n, _B + n - 1)


a, b = extract(B, C)
c, d = extract(B, C - 1)
res = (b - a + 1) + (d - c + 1) - max(0, min(b, d) - max(a, c) + 1)
print(res)
