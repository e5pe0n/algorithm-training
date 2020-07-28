N = int(input())
B = list(map(lambda x: int(x) - 1, input().split()))
res = []
for i in range(N):
    for j in range(len(B) - 1, -1, -1):
        if B[j] == j:
            res.append(B.pop(j))
            break
if len(B) == 0:
    for r in res[::-1]:
        print(r + 1)
else:
    print(-1)
