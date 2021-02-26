S = input()
res = 0
f = True
N = len(S)
for i in range(0, N - 1, 2):
    opr = int(S[i])
    op = S[i + 1]
    if op == '+':
        res += int(opr > 0 and f)
        f = True
    else:
        f &= opr > 0
res += int(int(S[N - 1]) > 0 and f)
print(res)
