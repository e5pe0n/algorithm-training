N, X = list(map(int, input().split()))
Y = list(map(int, input().split()))
Y.sort()


def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)


res = abs(X - Y[0])
for i in range(N - 1):
    res = gcd(res, Y[i + 1] - Y[i])
print(res)
