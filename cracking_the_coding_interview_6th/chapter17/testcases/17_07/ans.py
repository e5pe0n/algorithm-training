from collections import Counter


def ns(f):
    return next(f).strip()


with open("names02.txt") as f:
    cnt = Counter()
    n = int(ns(f))
    for _ in range(n):
        name, num = ns(f).split()
        cnt[name[0]] += int(num)


print(sorted(cnt.most_common()))
