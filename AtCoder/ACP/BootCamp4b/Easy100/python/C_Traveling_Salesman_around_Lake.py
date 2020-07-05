K, N = list(map(int, input().split()))
A = list(map(int, input().split()))

max_d = 0
max_idx = 0
D = []
for i in range(N - 1):
    D.append(min(abs(A[i + 1] - A[i]), abs(A[i] + (K - A[i + 1]))))
    if D[i] > max_d:
        max_d = D[i]
        max_idx = i
D.append(min(abs(A[N - 1] - A[0]), abs(A[0] + (K - A[N - 1]))))
if D[N - 1] > max_d:
    max_idx = N - 1

res = 0
for i in range(N):
    if i != max_idx:
        res += D[i]
print(res)
