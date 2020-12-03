N, M = map(int, input().split())
w = M - 2
_w = w
P = []
for i in range(M // 2):
    P.append((i + 1, i + 1 + _w + 1))
    _w -= 2
_w = w + 1
for i in range(M - M // 2):
    P.append((M + i + 1, M + i + 1 + _w + 1))
    _w -= 2
for p1, p2 in P:
    print(p1, p2)
