import sys
N = int(input())
A = list(map(int, input().split()))
i = 0
cnt = 0
while i < N:
    while i < N - 1 and A[i + 1] == A[i]:
        i += 1
    if i >= N - 1:
        cnt += 1
        print(cnt)
        sys.exit()
    if A[i + 1] < A[i]:
        while i < N - 1 and A[i + 1] <= A[i]:
            i += 1
    else:
        while i < N - 1 and A[i + 1] >= A[i]:
            i += 1
    cnt += 1
    i += 1
print(cnt)
