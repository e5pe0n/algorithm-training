N = int(input())
A = list(map(int, input().split()))
four = 0
odd = 0
for a in A:
    if a % 4 == 0:
        four += 1
    elif a % 2 != 0:
        odd += 1
if four >= odd - int(four + odd == N):
    print("Yes")
else:
    print("No")
