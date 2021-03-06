INF = float('inf')
N = int(input())
AB = [list(map(int, input().split())) for _ in range(N)]
res = INF
for i in range(N):
    a = AB[i][0]
    for j in range(N):
        b = AB[j][1]
        if i == j:
            res = min(res, a + b)
        else:
            res = min(res, max(a, b))
print(res)
