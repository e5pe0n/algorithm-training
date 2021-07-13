fp = "01.txt"


def ns(f):
    return next(f).strip()


with open(fp) as f:
    n = int(ns(f))
    lst = list(map(int, ns(f).split()))

b = [False] * n
for v in lst:
    b[v - 1] = True

res = [i + 1 for i in range(n) if not b[i]]
res_s = ' '.join(map(str, res))
with open(fp, 'a') as f:
    f.write(f"\n\nans: {res_s}")
