N = int(input())
S = input()

r, b, g = 0, 0, 0
for s in S:
    r += int(s == 'R')
    b += int(s == 'B')
    g += int(s == 'G')
res = r * b * g
for i in range(N - 2):
    j = i + 1
    while j + (j - i) < N:
        if S[i] != S[j] and S[j] != S[j + (j - i)] and S[j + (j - i)] != S[i]:
            res -= 1
        j += 1
print(res)
