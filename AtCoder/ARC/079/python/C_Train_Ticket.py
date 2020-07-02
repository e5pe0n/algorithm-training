import sys


S = [s for s in input()]
A = [int(s) for s in S]

for i in range(1 << 3):
    b = format(i, f'03b')[::-1]
    t = A[0]
    u = S[0]
    for j in range(3):
        if b[j] == '1':
            t += A[j + 1]
            u += "+" + S[j + 1]
        else:
            t -= A[j + 1]
            u += "-" + S[j + 1]
    if t == 7:
        print(u + "=7")
        sys.exit()
