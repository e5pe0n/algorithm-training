INF = float('inf')
N = int(input())
A = list(map(int, input().split()))

min_a = INF
res = 0
for a in A:
    if a <= min_a:
        res += 1
        min_a = a
print(res)
