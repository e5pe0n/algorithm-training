import sys
from collections import Counter
N = int(input())
C = Counter(list(map(int, input().split())))
if len(C) == 1 and C[0] == N:
    print('Yes')
elif len(C) == 2 and N % 3 == 0 and C[0] == N // 3 and N - C[0] == 2 * N // 3:
    print('Yes')
elif len(C) == 3 and N % 3 == 0:
    b = 0
    for c in C.most_common():
        if c[1] != N // 3:
            print('No')
            sys.exit()
        b ^= c[0]
    if b == 0:
        print('Yes')
    else:
        print('No')
else:
    print('No')
