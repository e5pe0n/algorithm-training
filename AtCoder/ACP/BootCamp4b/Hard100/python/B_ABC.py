s = input()
N = len(s)
i = 0
ans = 0
while i < N:
    while i < N and s[i] != 'A':
        i += 1
    cnt_A = 0
    while i < N and s[i] == 'A':
        while i < N and s[i] == 'A':
            cnt_A += 1
            i += 1
        while i + 1 < N and s[i:i + 2] == "BC":
            ans += cnt_A
            i += 2
print(ans)
