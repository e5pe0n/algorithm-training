N = int(input())
V = []
for i in range(N):
    a, b = map(int, input().split())
    V.append([a + b, a, b])
V.sort(reverse=True)
ans = 0
for i in range(N):
    if i % 2 == 0:
        ans += V[i][1]
    else:
        ans -= V[i][2]
print(ans)
