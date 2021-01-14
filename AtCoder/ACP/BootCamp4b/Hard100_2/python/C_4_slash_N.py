N = int(input())
for n in range(1, 3501):
    for w in range(1, 3501):
        p = N * n * w
        q = 4 * n * w - N * (w + n)
        if q > 0 and p % q == 0:
            h = p // q
            print(h, n, w)
            exit()
