A, B = map(int, input().split())
res = 0
for i in range(A, (A + 4 - 1) // 4 * 4):
    res ^= i
for i in range(B // 4 * 4, B + 1):
    res ^= i
print(res)
