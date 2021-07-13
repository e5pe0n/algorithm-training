import random

n = 10
fp = "01.txt"

lst = list(range(1, n + 1))
random.shuffle(lst)
res = lst[2:]
res_s = ' '.join(map(str, res))
with open(fp, "w") as f:
    f.write(f"{n}\n{res_s}")
