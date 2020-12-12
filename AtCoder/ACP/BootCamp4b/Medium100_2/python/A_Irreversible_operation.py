S = input()
b = 0
res = 0
for s in S:
    if s == 'B':
        b += 1
    else:
        res += b
print(res)
