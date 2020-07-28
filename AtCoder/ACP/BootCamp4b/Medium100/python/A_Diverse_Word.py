import sys
C = [0] * 26
S = input()
N = len(S)
for s in S:
    C[ord(s) - ord('a')] += 1
if N < 26:
    for i in range(26):
        if C[i] == 0:
            print(S + chr(i + ord('a')))
            sys.exit()
else:
    V = [S[N - 1]]
    i = N - 2
    while i >= 0:
        for v in V:
            if S[i] < v:
                print(S[:i] + v)
                sys.exit()
        V.append(S[i])
        V.sort()
        i -= 1
    print(-1)
