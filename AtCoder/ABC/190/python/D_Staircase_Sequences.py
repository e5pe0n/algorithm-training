N = int(input())
while N % 2 == 0:
    N //= 2
res = 0
for i in range(1, int(N ** 0.5) + 1):
    if N % i == 0:
        res += 1
        if N // i != i:
            res += 1
print(res * 2)
