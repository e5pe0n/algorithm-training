N = input()
res = sum(map(int, N))
res = max(res, max(0, int(N[0]) - 1 + 9 * (len(N) - 1)))
for i in range(1, len(N) - 1):
    if int(N[i]) > 0:
        t = 0
        for j in range(i):
            t += int(N[j])
        t += int(N[i]) - 1 + 9 * (len(N) - i - 1)
        res = max(res, t)
print(res)
