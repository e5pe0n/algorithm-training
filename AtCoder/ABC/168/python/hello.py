import re

p = re.compile(r"\((-?[0-9]+), (-?[0-9]+)\) ([0-9]+) \| \((-?[0-9]+), (-?[0-9]+)\) ([0-9]+)")


def ns(f):
    return next(f).strip()


lst = []
with open("out_sub1_12_py.txt", 'r') as f:
    for line in f:
        m = p.match(line)
        _lst = list(map(int, m.groups()))
        lst.append(_lst)

lst.sort()
with open("out2.txt", 'w') as f:
    for a1, b1, c1, a2, b2, c2 in lst:
        f.write(f"({a1}, {b1}) {c1} | ({a2}, {b2}) {c2}\n")
