N = int(input())
A = list(map(int, input().split()))

left = 0
right = 1
res = 0
while right < N:
    while right < N and A[right - 1] < A[right]:
        right += 1
    t = (right - left)
    res += t * (t - 1) // 2
    while right < N and A[right - 1] >= A[right]:
        right += 1
    left = right - 1
print(res + N)
