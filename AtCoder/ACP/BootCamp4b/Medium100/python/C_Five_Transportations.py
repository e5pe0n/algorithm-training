import math
N = int(input())
m = min([int(input()) for _ in range(5)])
print(math.ceil(N / m) + 4)
