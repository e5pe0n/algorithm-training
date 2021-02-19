N = int(input())


def divisors():
    res = []
    for i in range(1, int(N ** 0.5) + 1):
        if N % i == 0:
            res.append(i)
            if N // i != i:
                res.append(N // i)
    return res


divs = divisors()
sm = sum(divs) - N
if sm == N:
    print("Perfect")
elif sm < N:
    print("Deficient")
else:
    print("Abundant")
