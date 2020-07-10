import sys
N = int(input())
W = [input() for _ in range(N)]
for i in range(N - 1):
    if W[i][-1] != W[i + 1][0]:
        print('No')
        sys.exit()
    else:
        for j in range(i + 1):
            if W[j] == W[i + 1]:
                print('No')
                sys.exit()
print('Yes')
