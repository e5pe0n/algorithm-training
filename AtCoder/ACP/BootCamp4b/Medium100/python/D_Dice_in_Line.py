N, K = list(map(int, input().split()))
E = list(map(lambda x: (float(x) + 1) / 2, input().split()))
res = sum(E[:K])
t = res
for i in range(K, N):
    t += -E[i - K] + E[i]
    res = max(res, t)
print(res)
