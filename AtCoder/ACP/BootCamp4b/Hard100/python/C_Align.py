N = int(input())
A = [int(input()) for x in range(N)]
A.sort()
ans = 0

if N % 2 == 0:
    i = 0
    while i < N // 2 - 1:
        ans -= A[i] * 2
        i += 1
    ans -= A[i]
    i += 1
    ans += A[i]
    for i in range(i + 1, N):
        ans += A[i] * 2
else:
    ans1 = 0
    i = 0
    while i < (N - 3) // 2:
        ans1 -= A[i] * 2
        i += 1
    ans1 -= A[i]
    i += 1
    ans1 -= A[i]
    for i in range(i + 1, N):
        ans1 += A[i] * 2

    ans2 = 0
    i = 0
    while i < N // 2:
        ans2 -= A[i] * 2
        i += 1
    ans2 += A[i]
    i += 1
    ans2 += A[i]
    for i in range(i + 1, N):
        ans2 += A[i] * 2
    ans = max(ans1, ans2)

print(ans)
