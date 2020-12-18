S = input()
N = len(S)
if N < 26:
    used = [False] * 26
    for s in S:
        used[ord(s) - ord('a')] = True
    for i in range(26):
        if not used[i]:
            res = S + chr(i + ord('a'))
            break
else:
    V = [S[N - 1]]
    for i in range(N - 2, -1, -1):
        for v in V:
            if S[i] < v:
                res = S[:i] + v
                print(res)
                exit()
        V.append(S[i])
        V.sort()
        i -= 1
    res = -1
print(res)
