N, M = map(int, input().split())

x, y, z = -1, -1, -1
for j in range(M - 2 * N + 1):
    t = M - 2 * N - j
    if t % 2 == 0:
        k = t // 2
        i = N - j - k
        if i >= 0:
            x, y, z = i, j, k
            break
print(x, y, z)
