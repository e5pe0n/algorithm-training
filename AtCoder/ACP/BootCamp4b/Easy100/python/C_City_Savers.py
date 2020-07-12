N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

cnt = 0
for i in range(N - 1, -1, -1):
    cnt += min(A[i + 1], B[i])
    B[i] = max(0, B[i] - A[i + 1])
    cnt += min(A[i], B[i])
    A[i] = max(0, A[i] - B[i])
print(cnt)
