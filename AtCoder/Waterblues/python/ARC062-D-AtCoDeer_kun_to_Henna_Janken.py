S = input()
res = 0
for i in range(len(S)):
    if i % 2 == 0 and S[i] == 'p':
        res -= 1
    if i % 2 != 0 and S[i] == 'g':
        res += 1
print(res)
