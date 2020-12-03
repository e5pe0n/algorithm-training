X = int(input())
x = 100
res = 0
while x < X:
    x += x // 100
    res += 1
print(res)
