def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)


N = int(input())
res = int(input())
for _ in range(N - 1):
    t = int(input())
    res = res * t // gcd(res, t)
print(res)
