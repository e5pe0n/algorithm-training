import sys
S = input()
B = [False] * 26
for s in S:
    if B[ord(s) - ord('a')]:
        print('no')
        sys.exit()
    else:
        B[ord(s) - ord('a')] = True
print('yes')
