N, M = map(int, input().split())
C = [0] * N
for _ in range(M):
    a, b = map(lambda x: int(x) - 1, input().split())
    C[a] += 1
    C[b] += 1
if all(map(lambda x: x % 2 == 0, C)):
    print("YES")
else:
    print("NO")
