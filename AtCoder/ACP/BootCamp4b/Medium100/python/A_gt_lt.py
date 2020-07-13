S = input()
N = len(S)
A = [0] * (N + 1)
for i in range(N):
    if S[i] == '<':
        A[i + 1] = A[i] + 1
for i in range(N - 1, -1, -1):
    a = A[i + 1] + 1
    if S[i] == '>' and a > A[i]:
        A[i] = a
print(sum(A))
