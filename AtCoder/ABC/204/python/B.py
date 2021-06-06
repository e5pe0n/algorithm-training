N = int(input())
A = list(map(int, input().split()))

res = 0
for a in A:
    if a > 10:
        res += a - 10
print(res)
