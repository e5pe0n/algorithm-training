INF = float('inf')
A, B, W = map(int, input().split())
W *= 1000
ma = 0
mi = INF
for i in range(1, W // A + 1):
    if A <= W / i <= B:
        ma = max(ma, i)
        mi = min(mi, i)
if ma == 0:
    print("UNSATISFIABLE")
else:
    print(mi, ma)
