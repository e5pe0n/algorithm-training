MAX_N = 10**7
N = int(input())
ub = MAX_N + 1
lb = 0
while ub - lb > 1:
    md = (lb + ub) // 2
    if md * (md + 1) // 2 >= N:
        ub = md
    else:
        lb = md
for i in range(1, ub + 1):
    if i == ub * (ub + 1) // 2 - N:
        continue
    print(i)
