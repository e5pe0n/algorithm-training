import sys
S = input()
C = [False] * 26
for s in S:
    C[ord(s) - ord('a')] = True
for i in range(26):
    if not C[i]:
        print(chr(i + ord('a')))
        sys.exit()
print('None')
