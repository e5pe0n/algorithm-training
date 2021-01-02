N = int(input())
XY = [list(map(int, input().split())) for _ in range(N)]

res = 0
for i in range(N - 1):
    xi, yi = XY[i]
    for j in range(i + 1, N):
        xj, yj = XY[j]
        if abs(yi - yj) <= abs(xi - xj):
            res += 1
print(res)
