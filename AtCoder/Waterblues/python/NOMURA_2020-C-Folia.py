N = int(input())
A = list(map(int, input().split()))
B = [0] * (N + 2)
for i in range(N, -1, -1):
    B[i] = B[i + 1] + A[i]
cnt = 1
res = 0
for i in range(N + 1):
    res += cnt
    cnt -= A[i]
    if cnt < 0:
        res = -1
        break
    cnt = min(cnt * 2, B[i + 1])
print(res)
