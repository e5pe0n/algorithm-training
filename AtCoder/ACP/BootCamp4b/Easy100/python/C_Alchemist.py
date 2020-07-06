N = int(input())
V = list(map(int, input().split()))
V.sort()
res = 0.5 * (V[0] + V[1])
for i in range(2, N):
    res = 0.5 * (res + V[i])
print(res)
