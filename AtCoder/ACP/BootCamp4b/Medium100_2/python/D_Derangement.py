N = int(input())
P = list(map(lambda x: int(x) - 1, input().split()))

res = 0
for i in range(N - 1):
    if i == P[i]:
        P[i], P[i + 1] = P[i + 1], P[i]
        res += 1
if P[N - 1] == N - 1:
    res += 1
print(res)
