S = input()
N = len(S)

s = 0
for i in range(1 << (N - 1)):
    bs = format(i, f'0{N - 1}b')[::-1]
    t = S[0]
    for j in range(N - 1):
        if bs[j] == '1':
            s += int(t)
            t = S[j + 1]
        else:
            t += S[j + 1]
    s += int(t)
print(s)
