N = int(input())
A = list(map(int, input().split()))
B = A.copy()

for i in range(N, 0, -1):
    t = 0
    for j in range(i, N + 1, i):
        t += B[j - 1]
    if t % 2 != A[i - 1]:
        B[i - 1] = (B[i - 1] + 1) % 2
cnt = sum(B)
print(cnt)
if cnt == 0:
    exit()
print(' '.join([str(i + 1) for i in range(N) if B[i]]))
