import math
N = int(input())
n = int(math.ceil((-1 + math.sqrt(1 + 8 * N)) / 2))
d = n * (n + 1) // 2 - N
for i in range(1, n + 1):
    if i != d:
        print(i)
