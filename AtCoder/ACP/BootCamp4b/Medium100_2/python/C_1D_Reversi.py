S = input()
res = 0
for i in range(len(S) - 1):
    if S[i + 1] != S[i]:
        res += 1
print(res)
