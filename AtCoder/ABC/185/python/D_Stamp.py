N, M = list(map(int, input().split()))
A = [0] + sorted(list(map(int, input().split()))) + [N + 1]
if M == N:
    print("0")
    exit()
V = []
for i in range(M + 1):
    d = A[i + 1] - A[i] - 1
    if d > 0:
        V.append(d)
k = min(V)
res = 0
for v in V:
    res += (v + k - 1) // k
print(res)
