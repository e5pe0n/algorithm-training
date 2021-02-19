N, K = map(int, input().split())
A = [int(input()) for _ in range(N)]
if K == 1:
    print(N)
    exit()
cnt, res = 0, 0
for i in range(N - 1):
    if A[i + 1] - A[i] > 0:
        cnt += 1
        if cnt + 1 >= K:
            res += 1
    else:
        cnt = 0
print(res)
