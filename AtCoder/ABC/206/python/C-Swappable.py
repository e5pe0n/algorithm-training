from collections import Counter

N = int(input())
C = list(Counter(list(map(int, input().split()))).values())

M = len(C)
S = [0] * (M + 1)
for i in range(M):
    S[i + 1] = S[i] + C[i]
res = 0
for i in range(M):
    res += C[i] * (S[M] - S[i + 1])
print(res)
