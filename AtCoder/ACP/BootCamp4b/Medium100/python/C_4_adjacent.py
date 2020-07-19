N = int(input())
A = list(map(int, input().split()))
four_num = 0
odd_num = 0
for a in A:
    if a % 4 == 0:
        four_num += 1
    elif a % 2 == 1:
        odd_num += 1
t = 0
if four_num + odd_num == N:
    t = 1
if four_num >= odd_num - t:
    print('Yes')
else:
    print('No')
