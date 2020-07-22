N, C, K = list(map(int, input().split()))
T = [int(input()) for _ in range(N)]
T.sort()
i = 0
res = 0
while i < N:
    j = 0
    while i < N and j < C and T[i] - T[i - j] <= K:
        i += 1
        j += 1
    res += 1
print(res)
