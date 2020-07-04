N, A, B = [int(i) for i in input().split()]

res = 0
for i in range(1, N + 1):
    s = str(i)
    t = 0
    for c in s:
        t += int(c)
    if A <= t <= B:
        res += i
print(res)
