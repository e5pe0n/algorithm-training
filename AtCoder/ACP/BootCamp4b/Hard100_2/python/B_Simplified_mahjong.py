N = int(input())
A = [int(input()) for _ in range(N)] + [0]

res = 0
for i in range(N):
    t = (A[i] + A[i + 1]) // 2
    res += t
    A[i + 1] -= max(0, t * 2 - A[i])
print(res)
