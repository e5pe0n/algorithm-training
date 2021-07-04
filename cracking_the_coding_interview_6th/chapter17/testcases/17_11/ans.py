def ns(f):
    return next(f).strip()


with open("01.txt") as f:
    n = int(ns(f))
    words = [ns(f) for _ in range(n)]
    m = int(ns(f))
    pairs = [ns(f).split() for _ in range(m)]

for w1, w2 in pairs:
    w1_pos, w2_pos = [], []
    for i, w in enumerate(words):
        if w == w1:
            w1_pos.append(i)
        if w == w2:
            w2_pos.append(i)
    min_dist = float("inf")
    for p1 in w1_pos:
        for p2 in w2_pos:
            if min_dist > abs(p1 - p2):
                min_dist = abs(p1 - p2)
    print(f"d({w1}, {w2})={min_dist}")
