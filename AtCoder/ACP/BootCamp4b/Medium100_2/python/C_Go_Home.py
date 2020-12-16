X = int(input())
lb = 0
ub = X
while ub - lb > 1:
    md = (ub + lb) // 2
    if md * (md + 1) // 2 >= X:
        ub = md
    else:
        lb = md
print(ub)
