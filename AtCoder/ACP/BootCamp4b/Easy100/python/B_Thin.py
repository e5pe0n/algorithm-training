H, W = list(map(int, input().split()))
C = [None] * (2 * H)
for i in range(0, 2 * H, 2):
    C[i] = input()
    C[i + 1] = C[i]
for c in C:
    print(c)
