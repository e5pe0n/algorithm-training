N = int(input())
x = 200_001
P = list(map(int, input().split()))
cnt = 0
for p in P:
    if p < x:
        cnt += 1
        x = p
print(cnt)
