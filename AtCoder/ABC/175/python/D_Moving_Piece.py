INF = float('inf')


N, K = map(int, input().split())
P = list(map(lambda x: int(x) - 1, input().split()))
C = list(map(int, input().split()))

res = -INF
for i in range(N):
    s = [0] * (N + 1)
    used = [False] * N
    j = i
    k = 0
    while not used[j] and k < K:
        s[k + 1] = s[k] + C[j]
        used[j] = True
        j = P[j]
        k += 1
    max_s = max(s[1:k + 1])
    if s[k] <= 0:
        res = max(res, max_s)
        continue
    score = s[k] * max(0, K // k - 1) + max_s
    for j in range(1, K % k + 1):
        score = max(score, s[k] * (K // k) + s[j % k])
    res = max(res, score)
print(res)
