N = int(input())
res = 1_000_000_001
A = [int(i) for i in input().split()]
for a in A:
    cnt = 0
    while a % 2 == 0:
        a >>= 1
        cnt += 1
    res = min(res, cnt)
print(res)
