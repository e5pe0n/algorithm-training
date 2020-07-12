N = int(input())
n = 1
for i in range(1, N + 1):
    n = (n * i) % 1_000_000_007
print(n)
