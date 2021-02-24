from collections import Counter
S = input()
C = Counter()
res = 0
for i in range(len(S) - 1, 0, -1):
    cnt = 1
    if S[i - 1] == S[i]:
        for k, v in C.most_common():
            if k != S[i]:
                cnt += v
                res += v
                C[k] = 0
    C[S[i]] += cnt
print(res)
