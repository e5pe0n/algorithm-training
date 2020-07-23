MAX_Q = 500_001
OFFSET = 200_000
C = [None] * MAX_Q
S = input()
N = len(S)
for i in range(N):
    C[OFFSET + i] = S[i]
Q = int(input())
left = OFFSET - 1
right = N + OFFSET
flg = False
for _ in range(Q):
    T = input()
    if len(T) == 1:
        flg = not(flg)
    else:
        f, c = T.split()[1:]
        if ((not flg and f == '1') or (flg and f == '2')):
            C[left] = c
            left -= 1
        else:
            C[right] = c
            right += 1
if flg:
    print(''.join(C[right-1:left:-1]))
else:
    print(''.join(C[left+1:right]))
