INF = float('inf')
N, C = map(int, input().split())
A = [int(input()) - 1 for _ in range(N)]

res = INF
for i in range(10):
    for j in range(10):
        if i == j:
            continue
        t = 0
        for k, a in enumerate(A):
            if k % 2 == 0 and a != i:
                t += C
            elif k % 2 != 0 and a != j:
                t += C
        res = min(res, t)
print(res)
