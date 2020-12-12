S = input()

N = len(S)
V = [0] * (N + 1)
for i in range(N):
    if S[i] == '<':
        V[i + 1] = V[i] + 1
for i in range(N - 1, -1, -1):
    if S[i] == '>':
        V[i] = max(V[i + 1] + 1, V[i])
print(sum(V))
