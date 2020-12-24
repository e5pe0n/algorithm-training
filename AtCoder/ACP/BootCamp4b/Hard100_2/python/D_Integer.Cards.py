N, M = map(int, input().split())
A = sorted(list(map(int, input().split())))
V = sorted([list(map(int, input().split())) for _ in range(M)], key=lambda x: x[1])

idx = len(V) - 1
res = 0
for i in range(N):
    if idx < 0:
        res += A[i]
    else:
        res += max(A[i], V[idx][1])
        V[idx][0] -= 1
        if V[idx][0] == 0:
            idx -= 1
print(res)
