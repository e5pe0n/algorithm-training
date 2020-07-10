N, A, B = list(map(int, input().split()))
res = 0
for i in range(N + 1):
    s = str(i)
    t = 0
    for _s in s:
        t += int(_s)
    if A <= t <= B:
        res += i
print(res)
