N = int(input())
A = list(map(lambda x: int(x) + 1, input().split()))

bit = [0] * (N + 1)


def sum(i):
    global bit
    s = 0
    while i > 0:
        s += bit[i]
        i -= i & -i  # minus last 1 bit
    return s


def add(i, x):
    global bit
    while i <= N:
        bit[i] += x
        i += i & -i  # plus last 1 bit


res = 0
for i in range(N):
    res += i - sum(A[i])
    add(A[i], 1)
print(res)
for i in range(N - 1):
    res = res - (A[i] - 1) + (N - A[i])
    print(res)
