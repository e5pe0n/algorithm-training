N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
shortage = 0
res = 0
V = []
for i in range(N):
    V.append([A[i] - B[i], A[i], B[i]])
    if B[i] - A[i] > 0:
        res += 1
        shortage += B[i] - A[i]
if shortage == 0:
    print(res)
    exit()
for d, a, b in sorted(V, reverse=True):
    shortage -= d
    res += 1
    if shortage <= 0:
        print(res)
        exit()
print(-1)
