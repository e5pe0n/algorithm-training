N = int(input())
A = sorted(list(map(int, input().split())))

sm = A[0]
res = 0
for i in range(1, N):
    if sm * 2 >= A[i]:
        res += 1
    else:
        res = 0
    sm += A[i]
print(res + 1)
