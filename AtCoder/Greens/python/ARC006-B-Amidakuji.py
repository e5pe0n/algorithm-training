N, L = map(int, input().split())
S = [list(input()) for _ in range(L)]
s = input()
y = L - 1
x = s.find('o')
W = len(S[0])
for i in range(L - 1, -1, -1):
    for j in range(W):
        if i != y or j != x:
            continue
        left = x - 1
        right = x + 1
        if left >= 0 and S[i][left] == '-':
            x -= 2
            break
        if right < W and S[i][right] == '-':
            x += 2
            break
    y -= 1
print(x // 2 + 1)
