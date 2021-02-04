N = int(input())
if N % 2 != 0:
    print(0)
    exit()
res = 0
N //= 10
while N > 0:
    res += N
    N //= 5
print(res)
