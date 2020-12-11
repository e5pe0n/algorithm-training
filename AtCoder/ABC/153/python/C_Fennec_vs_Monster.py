N, K = map(int, input().split())
H = sorted(list(map(int, input().split())))

res = 0
for i in range(max(0, N - K)):
    res += H[i]
print(res)
