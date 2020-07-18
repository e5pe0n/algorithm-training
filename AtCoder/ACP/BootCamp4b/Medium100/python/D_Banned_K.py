N = int(input())
A = list(map(lambda x: int(x) - 1, input().split()))
C = [0] * N
for a in A:
    C[a] += 1


def comb(n):
    if n <= 1:
        return 0
    else:
        return n * (n - 1) // 2


t = sum(list(map(comb, C)))
for a in A:
    print(t - comb(C[a]) + comb(C[a] - 1))
