N = int(input())
K = list(map(int, input().split()))
res = [0] * N
res[0] = K[0]
res[N - 1] = K[N - 2]
for i in range(N - 2):
    res[i + 1] = min(K[i], K[i + 1])
print(' '.join(list(map(str, res))))
