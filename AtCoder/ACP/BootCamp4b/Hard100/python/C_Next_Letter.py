s = input()
K = int(input())

ans = ""
for _s in s[:-1]:
    d = (ord('z') - ord(_s) + 1) % 26
    if K >= d:
        K -= d
        ans += 'a'
    else:
        ans += _s
ans += chr(ord('a') + (ord(s[-1]) - ord('a') + K) % 26)
print(ans)
