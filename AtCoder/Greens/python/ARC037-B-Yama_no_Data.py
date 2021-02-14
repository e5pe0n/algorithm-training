N = int(input())
H = [0] + [int(input()) for _ in range(N)] + [0]
T = []
for i in range(1, N + 1):
    if H[i - 1] < H[i] and H[i] > H[i + 1]:
        T.append(i)
res = 0
for t in T:
    s = t
    u = t
    while s > 1 and H[s - 1] < H[s]:
        s -= 1
    while u < N and H[u + 1] < H[u]:
        u += 1
    res = max(res, u - s + 1)
print(res)
