import sys

N = input()

cnt = 1
for i in range(len(N) - 1):
    if N[i] == N[i + 1]:
        cnt += 1
        if cnt == 3:
            print('Yes')
            sys.exit()
    else:
        cnt = 1
print('No')
