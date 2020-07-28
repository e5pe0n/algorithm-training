MAX_N = 50
n = int(input())
C = [[0] * 26 for _ in range(n)]
for i in range(n):
    S = input()
    for s in S:
        C[i][ord(s) - ord('a')] += 1
res = ''
for i in range(26):
    t = MAX_N + 1
    for j in range(n):
        t = min(t, C[j][i])
    res += chr(i + ord('a')) * t
print(res)
