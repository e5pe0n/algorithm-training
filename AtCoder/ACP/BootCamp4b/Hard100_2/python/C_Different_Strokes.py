N = int(input())
AB = sorted([list(map(int, input().split())) for _ in range(N)], key=lambda x: x[0] + x[1], reverse=True)
res = 0
for i in range(N):
    if i % 2 == 0:
        res += AB[i][0]
    else:
        res -= AB[i][1]
print(res)
