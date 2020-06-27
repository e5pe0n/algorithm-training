I = input().split()
A, B = [int(i) for i in I]

cnt = 0
for i in range(A, B + 1):
    s = str(i)
    l = 0
    r = len(s) - 1
    while l < r and s[l] == s[r]:
        l += 1
        r -= 1
    if l >= r:
        cnt += 1
print(cnt)
