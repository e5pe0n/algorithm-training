from math import ceil


N = int(input())
print(int(ceil(N / 1000)) * 1000 - N)
