A = [list(map(int, input().split())) for _ in range(3)]
C = [0] * 8
N = int(input())
flg = False
for _ in range(N):
    b = int(input())
    if flg:
        continue
    for i in range(3):
        for j in range(3):
            if A[i][j] == b:
                C[i] += 1
                C[j + 3] += 1
                C[6] += 1 if i + j == 2 else 0
                C[7] += 1 if i == j else 0
                for c in C:
                    if c >= 3:
                        flg = True
                        break
if flg:
    print('Yes')
else:
    print('No')
