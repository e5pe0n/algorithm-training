S = input()
T = 'keyence'

NS = len(S)
NT = len(T)
for i in range(len(T) + 1):
    if S[:i] == T[:i] and S[NS - NT + i:] == T[i:]:
        print("YES")
        exit()
print("NO")
