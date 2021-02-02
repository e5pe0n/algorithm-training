N, K = map(int, input().split())
R, S, P = map(int, input().split())
T = list(input())

res = 0
for i in range(N):
    if T[i] == 'x':
        continue
    if T[i] == 'r':
        res += P
    if T[i] == 's':
        res += R
    if T[i] == 'p':
        res += S
    if i + K < N and T[i + K] == T[i]:
        T[i + K] = 'x'
print(res)
