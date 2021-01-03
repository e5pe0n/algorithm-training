from collections import Counter
MOD = 10**9 + 7
N = int(input())
C = Counter(list(map(int, input().split())))

res = 1
if N % 2 == 0:
    for i in range(1, N, 2):
        if C[i] != 2:
            res = 0
            break
        res = res * 2 % MOD
else:
    if C[0] != 1:
        res = 0
    else:
        for i in range(2, N, 2):
            if C[i] != 2:
                res = 0
                break
            res = res * 2 % MOD
print(res)
