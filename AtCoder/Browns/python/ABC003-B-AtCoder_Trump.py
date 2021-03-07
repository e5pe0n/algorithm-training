S = list(input())
T = list(input())
A = "atcoder"
win = "You can win"
lose = "You will lose"

for i in range(len(S)):
    if S[i] == T[i]:
        continue
    if T[i] == '@':
        S[i], T[i] = T[i], S[i]
    if S[i] != '@':
        print(lose)
        exit()
    f = False
    for a in A:
        if a == T[i]:
            f = True
            break
    if not f:
        print(lose)
        exit()
print(win)
