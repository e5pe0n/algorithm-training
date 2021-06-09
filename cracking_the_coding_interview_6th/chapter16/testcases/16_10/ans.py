def ns(f):
    return next(f).strip()


fp = "02.txt"
lst = []
with open(fp) as f:
    n = int(ns(f))
    for _ in range(n):
        lst.append(tuple(map(int, ns(f).split())))

ma_year = 1900
ma_cnt = 0
for year in range(1900, 2001):
    cnt = len(list(filter(lambda x: x[0] <= year <= x[1], lst)))
    if cnt > ma_cnt:
        ma_cnt = cnt
        ma_year = year
print(ma_cnt, ma_year)
