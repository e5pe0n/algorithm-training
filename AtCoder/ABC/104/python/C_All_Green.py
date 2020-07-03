D, G = [int(i) for i in input().split()]
P = []
C = []
for i in range(D):
    p, c = input().split()
    P.append(int(p))
    C.append(int(c))

res = 1000
for i in range(1 << D):
    b = format(i, '01000b')[::-1]
    s = 0
    cnt = 0
    k = 0
    for j in range(D):
        if b[j] == '1':
            s += 100 * (j + 1) * P[j] + C[j]
            cnt += P[j]
        else:
            k = j
    if s >= G:
        res = min(res, cnt)
    else:
        for l in range(P[k] - 1):
            s += 100 * (k + 1)
            cnt += 1
            if s >= G:
                res = min(res, cnt)
                break
print(res)
