N, K = map(int, input().split())


def pow(x, n):
    res = 1
    while n > 0:
        if n & 1:
            res *= x
        x *= x
        n >>= 1
    return res


res = 0
for i in range(1, N + 1):
    n = i
    cnt = 0
    while n < K:
        n <<= 1
        cnt += 1
    res += 1 / (N * pow(2, cnt))
print(f"{res:.10f}")
