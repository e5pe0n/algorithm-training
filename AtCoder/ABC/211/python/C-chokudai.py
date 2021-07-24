MOD = 10**9 + 7
S = input()

C = "chokudai"
c2i = dict(zip(C, range(len(C))))
d = {k: 0 for k in C}

for c in S:
    if c in d:
        prv = C[c2i[c] - 1]
        if c == 'c':
            d[c] += 1
        else:
            d[c] = (d[c] + d[prv]) % MOD

print(d['i'])
