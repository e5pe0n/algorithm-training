MOD = 10**9 + 7
N = int(input())
S1 = input()
S2 = input()
res = 3
i = 0
while i < N:
    if S1[i] == S2[i]:
        if i - 1 >= 0 and S1[i - 1] == S2[i - 1]:
            res = res * 2 % MOD
        i += 1
    else:
        if i - 1 >= 0 and S1[i - 1] != S2[i - 1]:
            res = res * 3 % MOD
        else:
            res = res * 2 % MOD
        i += 2
print(res)
