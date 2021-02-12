N, M = map(int, input().split())
A = list(range(N - 1, -1, -1))
for i in range(M):
    a = int(input())
    A[a - 1] = N + i
V = sorted(list(map(lambda x: (A[x], x), range(N))), reverse=True)
print('\n'.join(list(map(lambda x: str(x[1] + 1), V))))
