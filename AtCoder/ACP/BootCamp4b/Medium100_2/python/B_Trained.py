N = int(input())
A = [int(input()) - 1 for _ in range(N)]
i = 0
res = 0
used = [False] * N
while not used[i] and i != 1:
    used[i] = True
    i = A[i]
    res += 1
if i != 1:
    res = -1
print(res)
