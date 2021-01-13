S = input()
i = 0
a = 0
res = 0
while i < len(S) - 1:
    if S[i] == 'A':
        i += 1
        a += 1
    elif S[i] == 'B' and S[i + 1] == 'C':
        res += a
        i += 2
    else:
        a = 0
        i += 1
print(res)
