S = input()
N = len(S)
res = 0
for i in range(1 << (N - 1)):
    t = 0
    a = 0
    for j in range(N - 1):
        a += int(S[j])
        if i >> j & 1:
            t += a
            a = 0
        else:
            a *= 10
    a += int(S[N - 1])
    t += a
    res += t
print(res)
