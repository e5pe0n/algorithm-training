N, M, D = map(int, input().split())
p = 1 / N if D == 0 else 2 * (N - D) / N / N
res = p * (M - 1)
print(f"{res:.7f}")
