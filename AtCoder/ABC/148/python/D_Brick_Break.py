N = int(input())
A = list(map(int, input().split()))
res = 0
i = 0
for a in A:
    if i + 1 == a:
        i += 1
    else:
        res += 1
if i == 0:
    res = -1
print(res)
