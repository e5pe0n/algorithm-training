NS = 10**10 * 3
s = "110"
N = int(input())
T = input()
n = len(T)
res = 0
if n == 1:
    if T == "1":
        res = (NS // 3) * 2
    else:
        res = NS // 3
elif n == 2:
    if T == "11":
        res = NS // 3
    elif T == "10":
        res = NS // 3
    elif T == "01":
        res = NS // 3 - 1
    else:
        print(0)
        exit()
else:
    pre = T[0:3]
    if pre == "110":
        t = 0
    elif pre == "101":
        t = 1
    elif pre == "011":
        t = 2
    else:
        print(0)
        exit()
    for i in range(n):
        if T[i] != s[(i + t) % 3]:
            print(0)
            exit()
    if t == 0:
        res = NS // 3 - (n + 3 - 1) // 3 + 1
    elif t == 1:
        res = NS // 3 - (n // 3 + 1) + 1
    else:
        res = NS // 3 - (n + 4) // 3 + 1
print(res)
