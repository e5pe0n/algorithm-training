N, P = map(int, input().split())
A = list(map(int, input().split()))


def com(n, k):
    res = 1
    for i in range(1, k + 1):
        res = res * (n - i + 1) // i
    return res


odd = 0
even = 0
for a in A:
    if a % 2 == 0:
        even += 1
    else:
        odd += 1

t = 0
for i in range(even + 1):
    t += com(even, i)
res = 0
if P:
    for i in range(1, odd + 1, 2):
        res += com(odd, i) * t
else:
    for i in range(0, odd + 1, 2):
        res += com(odd, i) * t
print(res)
