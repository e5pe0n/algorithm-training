N = int(input())
A = set(map(int, input().split()))
res = 0
for a in A:
    if a % 2 != 0:
        res += 1
        continue
    f = True
    while a % 2 == 0:
        a //= 2
        if a in A:
            f = False
            break
    if f:
        res += 1
print(res)
