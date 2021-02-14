N = int(input())
S = str(N)
res = []
for i in range(1, len(S) * 9 + 1):
    x = N - i
    if x <= 0:
        continue
    s = x
    t = 0
    while s > 0:
        t += s % 10
        s //= 10
    if t == i:
        res.append(x)
res.sort()
print(len(res))
if res:
    print('\n'.join(list(map(str, res))))
