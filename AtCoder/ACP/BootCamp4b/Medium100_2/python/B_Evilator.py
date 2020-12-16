S = input()
N = len(S)
res = 0
for i, s in enumerate(S):
    if s == 'U':
        res += (N - i - 1) + i * 2
for i, s in enumerate(S[::-1]):
    if s == 'D':
        res += (N - i - 1) + i * 2
print(res)
