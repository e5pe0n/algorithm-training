def ns(f):
    return next(f).strip()


with open("../testset/counting_lattice_points_on_a_line_segment/test1.txt", 'r') as f:
    x1, y1 = map(int, ns(f).split())
    x2, y2 = map(int, ns(f).split())


def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)


a = abs(x1 - x2)
b = abs(y1 - y2)
ans = gcd(a, b) - 1
print(ans)
