import sys
N, x = list(map(int, input().split()))
A = list(map(int, input().split()))
A.sort()
i = 0
while i < N:
    if A[i] <= x:
        x -= A[i]
        i += 1
    else:
        print(i)
        sys.exit()
if x > 0:
    print(i - 1)
else:
    print(i)
