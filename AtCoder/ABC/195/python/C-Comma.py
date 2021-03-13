N = int(input())
S = str(N)
a = len(S) // 3
b = len(S) % 3
res = 0
if b == 0:
    ub = 1000
    lb = 1
    for i in range(a):
        if i == a - 1:
            res += (N - lb + 1) * i
        else:
            res += i * (ub - lb)
            lb = ub
            ub *= 10**3
else:
    ub = 1000
    lb = 1
    for i in range(a):
        res += i * (ub - lb)
        lb = ub
        ub *= 10**3
        i += 1
    res += (N - lb + 1) * a
print(res)
