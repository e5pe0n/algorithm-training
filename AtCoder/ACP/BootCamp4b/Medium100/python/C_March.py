from itertools import permutations
S = [0] * 5
B = [False, False, True, True, True]
N = int(input())
for _ in range(N):
    s = input()
    if s[0] == 'M':
        S[0] += 1
    elif s[0] == 'A':
        S[1] += 1
    elif s[0] == 'R':
        S[2] += 1
    elif s[0] == 'C':
        S[3] += 1
    elif s[0] == 'H':
        S[4] += 1
res = 0
for p in set(permutations(B)):
    t = 1
    for i in range(5):
        if p[i]:
            t *= S[i]
    res += t
print(res)
