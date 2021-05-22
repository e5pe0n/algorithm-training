S = list(input())[::-1]

for i, c in enumerate(S):
    if c == '6':
        S[i] = '9'
    if c == '9':
        S[i] = '6'

print(''.join(S))
