N, M = map(int, input().split())
X = sorted(list(map(int, input().split())))
if M == 1 or M <= N:
    print(0)
    exit()
dx = sorted([X[i + 1] - X[i] for i in range(M - 1)])
res = sum(dx[:M - 1 - (N - 1)])
print(res)
