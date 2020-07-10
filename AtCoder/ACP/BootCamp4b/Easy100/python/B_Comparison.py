import sys
A = input()
B = input()
if len(A) < len(B):
    print('LESS')
elif len(A) > len(B):
    print('GREATER')
else:
    for i in range(len(A)):
        if A[i] < B[i]:
            print('LESS')
            sys.exit()
        elif A[i] > B[i]:
            print('GREATER')
            sys.exit()
    print('EQUAL')
