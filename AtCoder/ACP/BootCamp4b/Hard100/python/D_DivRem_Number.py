import math


N = int(input())

ans = 0
for i in range(1, int(math.ceil(N ** 0.5))):
    if N % i == 0 and N // i - 1 != i:
        ans += N // i - 1
print(ans)
