S = input()
C = ['1', '0']
c = S[0]
cnt = 0
for i in range(1, len(S)):
    if c == S[i]:
        c = C[ord(c) - ord('0')]
        cnt += 1
    else:
        c = S[i]
print(cnt)
