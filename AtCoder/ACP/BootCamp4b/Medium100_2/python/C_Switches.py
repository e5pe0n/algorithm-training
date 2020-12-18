N, M = map(int, input().split())
S = [list(map(lambda x: int(x) - 1, input().split()))[1:] for _ in range(M)]
P = list(map(int, input().split()))


res = 0
for i in range(1 << N):
    cnt = 0
    C = [0] * M
    for j in range(M):
        for s in S[j]:
            if i >> s & 1:
                C[j] += 1
        if C[j] % 2 == P[j]:
            cnt += 1
    if cnt == M:
        res += 1
print(res)
