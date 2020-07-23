import sys
N = int(input())
A = list(map(int, input().split()))
a = min(A)
b = a
while True:
    for _a in A:
        _b = _a % a
        if _b > 0 and _b < a:
            b = _b
    if b == a:
        print(a)
        sys.exit()
    a = b
