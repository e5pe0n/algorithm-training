import sys
C = [list(map(int, input().split())) for _ in range(3)]
for i in range(3):
    if not ((C[i][0] - C[(i + 1) % 3][0]) == (C[i][1] - C[(i + 1) % 3][1]) == (C[i][2] - C[(i + 1) % 3][2])):
        print('No')
        sys.exit()
for j in range(3):
    if not ((C[0][j] - C[0][(j + 1) % 3]) == (C[1][j] - C[1][(j + 1) % 3]) == (C[2][j] - C[2][(j + 1) % 3])):
        print('No')
        sys.exit()
print('Yes')
