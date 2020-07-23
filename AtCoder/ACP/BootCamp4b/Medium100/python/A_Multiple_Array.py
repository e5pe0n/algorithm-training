N = int(input())
X = [list(map(int, input().split())) for _ in range(N)]
res = 0
for i in range(N - 1, - 1, -1):
    res += (X[i][1] - (X[i][0] + res) % X[i][1]) % X[i][1]
print(res)
