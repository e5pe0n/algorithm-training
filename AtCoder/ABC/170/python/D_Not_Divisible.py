MAX_A = int(1e6)


N = int(input())
A = list(map(int, input().split()))


def divisors(n):
    res = []
    for i in range(1, int(n ** 0.5) + 1):
        if n % i == 0:
            res.append(i)
            if n // i != i:
                res.append(n // i)
    return res


cnt = [0] * (MAX_A + 1)
for a in A:
    cnt[a] += 1
res = 0
for a in A:
    v = divisors(a)
    found = False
    for d in v:
        if a == d and cnt[a] == 1:
            continue
        if cnt[d] > 0:
            found = True
            break
    if not found:
        res += 1
print(res)
