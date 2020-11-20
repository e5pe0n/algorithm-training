N = input()
fN = 0
for n in N:
    fN += int(n)
if int(N) % fN == 0:
    print('Yes')
else:
    print('No')
