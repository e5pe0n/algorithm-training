import sys
N, A, B = list(map(int, input().split()))
if A > B:
    print(0)
    sys.exit()
if N == 1:
    if A == B:
        print(1)
    else:
        print(0)
elif N == 2:
    print(1)
else:
    print((B - A) * (N - 2) + 1)
