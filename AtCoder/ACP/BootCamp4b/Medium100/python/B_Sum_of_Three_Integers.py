K, S = list(map(int, input().split()))
res = 0
for i in range(K + 1):
    for j in range(K + 1):
        k = S - i - j
        if (k >= 0 and k <= K):
            res += 1
print(res)
