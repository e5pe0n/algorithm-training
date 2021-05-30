N, K = map(int, input().split())
AB = sorted([list(map(int, input().split())) for _ in range(N)])
last = 0
for i in range(0, N):
    if K - (AB[i][0] - last) < 0:
        break
    K += AB[i][1] - (AB[i][0] - last)
    last = AB[i][0]
print(last + K)
