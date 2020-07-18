import sys
N = int(input())
s = input()
t = input()
for i in range(N):
    flg = True
    for j in range(N - i):
        if s[i + j] != t[j]:
            flg = False
            break
    if flg:
        print(N + i)
        sys.exit()
print(2 * N)
