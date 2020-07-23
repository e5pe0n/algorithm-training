N = int(input())
P = list(map(lambda x: int(x) - 1, input().split()))
i = 0
res = 0
while i < N:
    cnt = 0
    while i < N and i == P[i]:
        i += 1
        cnt += 1
    res += (cnt + 1) // 2
    while i < N and i != P[i]:
        i += 1
print(res)
