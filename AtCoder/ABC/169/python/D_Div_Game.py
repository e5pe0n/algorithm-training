N = int(input())


def prime_factorize(n):
    res = []
    for i in range(2, int(n ** 0.5) + 1):
        cnt = 0
        while n % i == 0:
            n /= i
            cnt += 1
        res.append(cnt)
    if n > 1:
        res.append(1)
    return res


v = prime_factorize(N)
res = 0
for cnt in v:
    lb = 0
    ub = cnt + 1
    while ub - lb > 1:
        md = (ub + lb) // 2
        if md * (md + 1) // 2 <= cnt:
            lb = md
        else:
            ub = md
    res += lb
print(res)
