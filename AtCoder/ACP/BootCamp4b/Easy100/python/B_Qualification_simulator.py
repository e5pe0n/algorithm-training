N, A, B = list(map(int, input().split()))
S = input()

a = 0
b = 0
for s in S:
    if s == 'a':
        if a + b < A + B:
            print('Yes')
            a += 1
        else:
            print('No')
    elif s == 'b':
        if (a + b < A + B) and b < B:
            print('Yes')
            b += 1
        else:
            print('No')
    else:
        print('No')
