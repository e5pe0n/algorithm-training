N, A, B, C, D = map(lambda x: int(x) - 1, input().split())
N += 1
S = input()
rock = 0
for i in range(A, C):
    if S[i] == '.':
        rock = 0
    else:
        rock += 1
        if rock >= 2:
            print("No")
            exit()
rock = 0
for i in range(B, D):
    if S[i] == '.':
        rock = 0
    else:
        rock += 1
        if rock >= 2:
            print("No")
            exit()
if C > D:
    space = 0
    for i in range(B - 1, D + 2):
        if S[i] == '.':
            space += 1
            if space >= 3:
                break
        else:
            space = 0
    if space < 3:
        print("No")
        exit()
print("Yes")
