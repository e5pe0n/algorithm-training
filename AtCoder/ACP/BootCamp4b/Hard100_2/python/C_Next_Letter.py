S = list(input())
K = int(input())

N = len(S)
for i, s in enumerate(S):
    t = (26 - (ord(s) - ord('a'))) % 26
    if t <= K:
        K -= t
        S[i] = 'a'
S[N - 1] = chr(ord(S[N - 1]) + K % 26)
print(''.join(S))
