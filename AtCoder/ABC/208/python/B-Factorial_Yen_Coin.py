parms = [1]
for i in range(1, 15):
    parms.append(parms[-1] * i)

P = int(input())
res = 0
for i in range(14, 0, -1):
    res += min(100, P // parms[i])
    P %= parms[i]
print(res)
