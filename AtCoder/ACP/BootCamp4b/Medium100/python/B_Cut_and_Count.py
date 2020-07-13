N = int(input())
S = input()
C = [[-1, -1] for _ in range(26)]
for i in range(N):
    c = ord(S[i]) - ord('a')
    if C[c][0] == -1:
        C[c][0] = i
    else:
        C[c][1] = i
print(max([len(tuple(filter(lambda x: x[0] <= i < x[1], C))) for i in range(N)]))
