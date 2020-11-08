N = int(input())
A = list(map(int, input().split()))

C = [0]
t = 0
m = 0
res = 0
for i in range(N):
    C.append(C[i] + A[i])
    m = max(m, C[i + 1])
    res = max(res, t + m)
    t += C[i + 1]
print(res)
