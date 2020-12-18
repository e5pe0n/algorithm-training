N = int(input())
X = [int(input()) for _ in range(5)]

min_x = min(X)
res = 5 + (N - 1) // min_x
print(res)
