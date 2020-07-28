N = int(input())
S = input()
C = [0] * N
t = 0
for i in range(N):
    C[i] = t
    if S[i] == 'W':
        t += 1
t = 0
for i in range(N - 1, -1, -1):
    C[i] += t
    if S[i] == 'E':
        t += 1
print(min(C))
