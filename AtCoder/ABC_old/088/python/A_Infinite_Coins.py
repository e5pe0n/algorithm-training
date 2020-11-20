N = input()
A = input()
N, A = int(N), int(A)

while N >= 0:
    N -= 500

if N + 500 - A <= 0:
    print('Yes')
else:
    print('No')
