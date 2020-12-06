A = [list(map(int, input().split())) for _ in range(3)]
N = int(input())
B = [int(input()) for _ in range(N)]

cnt = [0] * 8
for b in B:
    for i in range(3):
        for j in range(3):
            if A[i][j] == b:
                cnt[i] += 1
                cnt[j + 3] += 1
                if i + j == 2:
                    cnt[6] += 1
                if i == j:
                    cnt[7] += 1
if any([x >= 3 for x in cnt]):
    print("Yes")
else:
    print("No")
