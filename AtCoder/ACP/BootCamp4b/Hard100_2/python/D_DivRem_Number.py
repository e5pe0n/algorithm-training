N = int(input())
res = 0
for i in range(1, int(N**0.5) + 1):
    if N % i == 0 and N // i - 1 > i:
        res += N // i - 1
print(res)
