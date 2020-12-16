N, M = map(int, input().split())
AB = [list(map(lambda x: int(x) - 1, input().split())) for _ in range(M)]
A = [0] * N
V = []
for a, b in AB:
    if a == 0:
        V.append(b)
    A[a] = b
for v in V:
    if A[v] == N - 1:
        print("POSSIBLE")
        exit()
print("IMPOSSIBLE")
