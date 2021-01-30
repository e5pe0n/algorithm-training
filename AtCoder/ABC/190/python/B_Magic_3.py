N, S, D = map(int, input().split())
XY = [list(map(int, input().split())) for _ in range(N)]

f = False
for x, y in XY:
    if x < S and y > D:
        f = True
if f:
    print("Yes")
else:
    print("No")
