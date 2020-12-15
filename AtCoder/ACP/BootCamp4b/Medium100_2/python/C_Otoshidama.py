N, Y = map(int, input().split())
NA = Y // 10000
NB = Y // 5000
for i in range(NA + 1):
    for j in range(NB + 1):
        k = (Y - 10000 * i - 5000 * j) // 1000
        if k >= 0 and i + j + k == N:
            print(i, j, k)
            exit()
print(-1, -1, -1)
