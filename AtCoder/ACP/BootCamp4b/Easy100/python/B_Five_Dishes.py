X = []
n = 0
idx = 0
for i in range(5):
    x = int(input())
    X.append(x)
    m = (10 - x % 10) % 10
    if n < m:
        n = m
        idx = i
res = 0
for i in range(5):
    if i != idx:
        res += (10 - X[i] % 10) % 10 + X[i]
print(res + X[idx])
