N = int(input())
if N % 2 != 0:
    print(0)
    exit()
N //= 10
res = N
while N > 0:
    N //= 5
    res += N
print(res)
