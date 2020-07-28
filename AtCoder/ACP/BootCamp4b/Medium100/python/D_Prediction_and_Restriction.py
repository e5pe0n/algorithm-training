N, K = list(map(int, input().split()))
R, S, P = list(map(int, input().split()))
T = list(input())
res = 0
for i in range(N):
    if T[i] == 'r':
        res += P
        if i + K < N and T[i + K] == 'r':
            T[i + K] = 'x'
    if T[i] == 's':
        res += R
        if i + K < N and T[i + K] == 's':
            T[i + K] = 'x'
    if T[i] == 'p':
        res += S
        if i + K < N and T[i + K] == 'p':
            T[i + K] = 'x'
print(res)
