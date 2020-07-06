N = int(input())
D, X = list(map(int, input().split()))
cnt = 0
for i in range(N):
    a = int(input())
    j = 1
    d = 1
    while d <= D:
        cnt += 1
        d = j * a + 1
        j += 1
print(cnt + X)
