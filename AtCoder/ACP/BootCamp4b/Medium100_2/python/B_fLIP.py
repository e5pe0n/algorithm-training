N, M, K = map(int, input().split())
if K % M == 0 or K % N == 0:
    print("Yes")
    exit()
for i in range(N):
    for j in range(M):
        n = (N - (i + 1)) * (j + 1) + (M - (j + 1)) * (i + 1)
        if n == K:
            print("Yes")
            exit()
print("No")
