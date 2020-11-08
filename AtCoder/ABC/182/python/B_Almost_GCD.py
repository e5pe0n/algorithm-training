N = int(input())
A = list(map(int, input().split()))

mcnt = 0
res = 0
for k in range(2, max(A) + 1):
    cnt = 0
    for a in A:
        if a % k == 0:
            cnt += 1
    if mcnt < cnt:
        mcnt = cnt
        res = k
print(res)
