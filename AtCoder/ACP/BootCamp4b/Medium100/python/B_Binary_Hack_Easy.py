s = input()
i = len(s) - 1
res = ''
while i >= 0:
    while i >= 0 and s[i] != 'B':
        res += s[i]
        i -= 1
    cnt = 0
    while i >= 0 and s[i] == 'B':
        i -= 1
        cnt += 1
    i -= cnt
print(res[::-1])
