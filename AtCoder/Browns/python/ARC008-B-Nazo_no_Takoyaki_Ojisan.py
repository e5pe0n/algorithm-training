from collections import Counter
N, M = map(int, input().split())
name = input()
kit = input()
Cname = Counter(name)
Ckit = Counter(kit)
res = 0
for k, v in Cname.most_common():
    cnt_name = v
    cnt_kit = Ckit[k]
    if cnt_kit == 0:
        res = -1
        break
    res = max(res, (cnt_name + cnt_kit - 1) // cnt_kit)
print(res)
