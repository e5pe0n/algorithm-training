N = int(input())
S = input()
E = [0] * N
W = [0] * N
for i in range(N - 1):
    W[i + 1] = W[i] + int(S[i] == 'W')
for i in range(N - 1, 0, -1):
    E[i - 1] = E[i] + int(S[i] == 'E')
res = min(list(map(lambda x: x[0] + x[1], zip(W, E))))
print(res)
