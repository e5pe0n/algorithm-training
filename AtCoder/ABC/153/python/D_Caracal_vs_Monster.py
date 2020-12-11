H = int(input())

res = 0
x = 1
while H > 0:
    res += x
    H //= 2
    x *= 2
print(res)
