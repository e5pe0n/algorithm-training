S, T = map(int, input().split())
MAX_S = 100
MAX_T = 10000
cnt = 0
for a in range(MAX_S + 1):
    for b in range(MAX_S + 1):
        for c in range(MAX_S + 1):
            if a + b + c <= S and a * b * c <= T:
                cnt += 1
print(cnt)
