import sys
import math
X = int(input())
if X == 2:
    print(2)
    sys.exit()
if X % 2 == 0:
    X += 1

while True:
    s = int(math.sqrt(X))
    flg = True
    for i in range(3, s, 2):
        if X % i == 0:
            flg = False
            break
    if flg:
        print(X)
        sys.exit()
    else:
        X += 2
