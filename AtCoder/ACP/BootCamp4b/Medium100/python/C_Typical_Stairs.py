MOD = 10 ** 9 + 7
N, M = list(map(int, input().split()))
B = [True] * (N + 1)
D = [1] + [0] * N
for _ in range(M):
    a = int(input())
    B[a] = False
for i in range(N):
    for j in range(i + 1, min(N, i + 2) + 1):
        if B[j]:
            D[j] = (D[j] + D[i]) % MOD
print(D[N])
