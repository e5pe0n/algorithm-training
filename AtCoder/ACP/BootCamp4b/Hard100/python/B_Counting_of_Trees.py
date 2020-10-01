from collections import Counter
import sys


MOD = 998_244_353


N = int(input())
D = [int(x) for x in input().split()]
if D[0] != 0:
    print(0)
    sys.exit()

_c = 1
ans = 1
for i, p in enumerate(sorted(Counter(D).most_common())):
    if p[0] == 0 and p[1] > 1:
        ans = 0
        break
    if i != p[0]:
        ans = 0
        break
    ans *= _c ** p[1]
    _c = p[1]
print(ans % MOD)
