N = 20

res = 0
for i in range(1, 19 + 1):
    t = 1
    for j in range(1, i + 1):
        t = t * (19 - j + 1) / j
    res += t
print(res)
