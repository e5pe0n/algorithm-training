import sys
from collections import Counter
N = int(input())
D = Counter(list(map(int, input().split())))
M = int(input())
T = list(map(int, input().split()))
for t in T:
    if D[t] <= 0:
        print('NO')
        sys.exit()
    else:
        D[t] -= 1
print('YES')
