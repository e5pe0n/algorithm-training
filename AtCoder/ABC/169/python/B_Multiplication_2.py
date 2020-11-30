THRE = int(1e18)


N = int(input())
A = list(map(int, input().split()))

if 0 in A:
    print(0)
    exit()
res = 1
for a in A:
    res *= a
    if res > THRE:
        res = -1
        break
print(res)
