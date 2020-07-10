N = int(input())
A = list(map(int, input().split()))
cnt = 0
n = 0
for i in range(N):
    if A[i] - 1 == n:
        n += 1
    else:
        cnt += 1
if cnt == N:
    print(-1)
else:
    print(cnt)
