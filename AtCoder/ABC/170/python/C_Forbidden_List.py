X, N = map(int, input().split())
p = [-1] + sorted(list(map(int, input().split()))) + [102]

d = float('inf')
res = 0
for i in range(len(p) - 1):
    for j in range(p[i] + 1, p[i + 1]):
        if abs(j - X) < d:
            d = abs(j - X)
            res = j
print(res)
