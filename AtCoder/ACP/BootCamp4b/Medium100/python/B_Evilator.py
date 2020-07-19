S = input()
N = len(S)
res = 0
for i in range(N):
    if S[i] == 'U':
        res += N - i - 1 + 2 * i
    else:
        res += 2 * (N - i - 1) + i
print(res)
