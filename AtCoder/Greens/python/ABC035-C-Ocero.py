N, Q = map(int, input().split())
L = [0] * N
R = [0] * (N + 1)
for _ in range(Q):
    left, right = map(int, input().split())
    L[left - 1] += 1
    R[right] += 1
res = 0
for i in range(N):
    res += L[i] - R[i]
    print(res % 2, end="")
print()
