N = int(input())
A = list(map(int, input().split()))
sm = sum(A)
if sm % N != 0:
    print(-1)
    exit()
t = 0
m = sum(A) // N
res = 0
for a in A:
    t += m - a
    if t != 0:
        res += 1
print(res)
