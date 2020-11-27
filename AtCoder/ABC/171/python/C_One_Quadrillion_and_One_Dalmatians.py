N = int(input()) - 1

V = []
while N >= 0:
    V.append(N % 26)
    N = N // 26 - 1
res = ''
for v in V[::-1]:
    res += chr(v + ord('a'))
print(res)
