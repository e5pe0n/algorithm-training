N = int(input())
S = list(input())
Q = int(input())
offset = 0
L = list(range(N * 2))
for _ in range(Q):
    T, A, B = map(int, input().split())
    A -= 1
    B -= 1
    if T == 2:
        offset = (offset + N) % (2 * N)
    else:
        a = (A + offset) % (2 * N)
        b = (B + offset) % (2 * N)
        L[a], L[b] = L[b], L[a]
res = []
for i in range(2 * N):
    res.append(S[L[(i + offset) % (2 * N)]])
print(''.join(res))
