N, M = list(map(int, input().split()))
t = 1900 * M + 100 * (N - M)
print(t * 2 ** M)
