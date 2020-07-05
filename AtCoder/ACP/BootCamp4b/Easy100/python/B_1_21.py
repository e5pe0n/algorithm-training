import math
a, b = list(map(int, input().split()))
n = int(str(a) + str(b))
_n = int(math.sqrt(n))
if _n ** 2 == n:
    print('Yes')
else:
    print('No')
