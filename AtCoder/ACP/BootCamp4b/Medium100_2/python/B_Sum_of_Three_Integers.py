K, S = map(int, input().split())
res = 0
for x in range(K + 1):
    for y in range(K + 1):
        z = S - x - y
        if 0 <= z <= K:
            res += 1
print(res)
