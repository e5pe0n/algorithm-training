N = int(input())
cnt = 0
for _ in range(N):
    l, r = input().split()
    cnt += int(r) - int(l) + 1
print(cnt)
