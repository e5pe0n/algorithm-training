N = int(input())
A = list(map(int, input().split()))
A.sort()


def prime_factorize(n):
    res = []
    for i in range(2, int(n ** 0.5) + 1):
        if n % i != 0:
            continue
        while n % i == 0:
            n //= i
        res.append(i)
    if n != 1:
        res.append(n)
    return res


def solve():
    used = [False] * (A[-1] + 1)
    res = 0
    for a in A:
        V = prime_factorize(a)
        for v in V:
            if used[v]:
                res = 2
                break
            for k in range(v, A[-1] + 1, v):
                used[k] = True
        if res == 2:
            break
    if res == 0:
        return 0
    V = prime_factorize(A[0])
    cnt = 0
    for v in V:
        for a in A:
            if a % v != 0:
                cnt += 1
                break
    return 1 if cnt == len(V) else 2


res = solve()
if res == 0:
    print('pairwise coprime')
elif res == 1:
    print('setwise coprime')
else:
    print('not coprime')
