import math
X = int(input())
if X >= math.ceil((X % 100) / 5) * 100:
    print(1)
else:
    print(0)
