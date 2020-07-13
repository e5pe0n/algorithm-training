import sys
S = input()[:-2]
while len(S) > 0:
    if S[:len(S) // 2] == S[len(S) // 2:]:
        print(len(S))
        sys.exit()
    S = S[:-2]
