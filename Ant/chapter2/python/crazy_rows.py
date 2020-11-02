def ns(f):
    return next(f).strip()


with open("../testset/crazy_rows/test3.txt", 'r') as f:
    N = int(ns(f))
    a = [-1] * N
    for i in range(N):
        s = ns(f)
        for j in range(N):
            if s[j] == '1':
                a[i] = j

res = 0
for i in range(N):
    pos = -1
    for j in range(i, N):
        if a[j] <= i:
            pos = j
            break
    for j in range(pos, i, -1):
        a[j], a[j - 1] = a[j - 1], a[j]
        res += 1
print(res)
