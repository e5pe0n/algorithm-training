K = int(input())
a, b = 1, 0
while K >= 0:
    K -= 1
    r = b
    b = a
    a = b + r
print(a, b)
