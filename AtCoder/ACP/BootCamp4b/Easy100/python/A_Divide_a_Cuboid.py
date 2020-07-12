V = list(map(int, input().split()))
V.sort()
L = V[2] // 2
print(V[0] * V[1] * (V[2] - L - L))
