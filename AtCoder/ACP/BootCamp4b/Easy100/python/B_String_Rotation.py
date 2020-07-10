import sys
S = input()
T = input()

for i in range(len(S)):
    flg = True
    for j in range(i, len(S)):
        if S[j] != T[j - i]:
            flg = False
            break
    if not flg:
        continue
    for j in range(i):
        if S[j] != T[j + len(S) - i]:
            flg = False
            break
    if flg:
        print('Yes')
        sys.exit()
print('No')
