n = int(input())

lb = 0
ub = n + 1
while ub - lb > 1:
    md = (lb + ub) // 2
    if md * (md + 1) // 2 <= n + 1:
        lb = md
    else:
        ub = md
print(n - lb + 1)
