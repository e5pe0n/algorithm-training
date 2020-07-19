s = input()
N = len(s)
res = N
for i in range(26):
    j = 0
    t = 0
    while j < N:
        cnt = 0
        while j < N and s[j] == chr(i + ord('a')):
            j += 1
        while j < N and s[j] != chr(i + ord('a')):
            cnt += 1
            j += 1
        t = max(t, cnt)
    res = min(res, t)
print(res)
