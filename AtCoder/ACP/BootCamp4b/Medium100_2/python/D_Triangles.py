from bisect import bisect_left
N = int(input())
L = sorted(list(map(int, input().split())))

res = 0
for i in range(N - 1):
    for j in range(i + 1, N):
        t = bisect_left(L, L[i] + L[j]) - j - 1
        res += max(0, t)
print(res)
