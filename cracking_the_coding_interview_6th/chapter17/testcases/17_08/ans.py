def ns(f):
    return next(f).strip()


with open("02.txt") as f:
    n = int(ns(f))
    hw = sorted([list(map(int, ns(f).split())) for _ in range(n)])

res = 0
ma_lst = []
for i in range(1 << n):
    lst = []
    for j in range(n):
        if i >> j & 1:
            lst.append(hw[j])
    f = True
    for j in range(len(lst) - 1):
        if lst[j][1] >= lst[j + 1][1]:
            f = False
            break
    if f:
        if res < len(lst):
            res = len(lst)
            ma_lst = lst

print(res)
print(ma_lst)
