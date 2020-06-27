N = int(input())
K = int(input())
n = 1
for i in range(N):
    n = min(n * 2, n + K)
print(n)
