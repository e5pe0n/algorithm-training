N = int(input())
s = input()
t = input()

res = N
for i in range(N):
    f = True
    for j in range(i, N):
        if s[j] != t[j - i]:
            f = False
            break
    if f:
        break
    res += 1
print(res)
