import math
A, B = list(map(int, input().split()))
a = math.ceil(A / 0.08)
b = math.ceil(B / 0.1)
if a == b:
    print(a)
else:
    if a < b and int(b * 0.08) == A:
        print(b)
    elif a > b and int(a * 0.1) == B:
        print(a)
    else:
        print(-1)
