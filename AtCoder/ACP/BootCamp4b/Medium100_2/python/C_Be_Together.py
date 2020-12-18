INF = float('inf')
N = int(input())
A = list(map(int, input().split()))

res = INF
for i in range(-100, 100 + 1):
    res = min(res, sum(list(map(lambda x: (i - x) ** 2, A))))
print(res)
