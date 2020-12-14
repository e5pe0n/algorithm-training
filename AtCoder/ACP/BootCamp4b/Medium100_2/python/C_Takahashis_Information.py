C = [list(map(int, input().split())) for _ in range(3)]

cnt = 0
for i in range(3):
    if C[i][0] - C[(i + 1) % 3][0] == C[i][1] - C[(i + 1) % 3][1] and C[i][1] - C[(i + 1) % 3][1] == C[i][2] - C[(i + 1) % 3][2]:
        cnt += 1
for j in range(3):
    if C[0][j] - C[0][(j + 1) % 3] == C[1][j] - C[1][(j + 1) % 3] and C[1][j] - C[1][(j + 1) % 3] == C[2][j] - C[2][(j + 1) % 3]:
        cnt += 1
if cnt == 6:
    print("Yes")
else:
    print("No")
