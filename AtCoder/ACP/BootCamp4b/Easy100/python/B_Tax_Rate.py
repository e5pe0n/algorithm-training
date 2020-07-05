import math

N = int(input())
x = int(math.ceil(N / 1.08))
if int(x * 1.08) == N:
    print(x)
else:
    print(':(')
