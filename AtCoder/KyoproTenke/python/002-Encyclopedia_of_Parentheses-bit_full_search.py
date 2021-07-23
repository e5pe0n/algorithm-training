N = int(input())
if N % 2 != 0:
    exit()

for i in range(1 << N):
    t = 0
    s = []
    for j in range(N - 1, -1, -1):
        if i >> j & 1:
            t -= 1
            s.append(')')
        else:
            t += 1
            s.append('(')
        if t < 0:
            break
    if t == 0:
        print(''.join(s))
