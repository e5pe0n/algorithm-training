N, K = map(int, input().split())
res = (6.0 * (N - K) * (K - 1) + 3.0 * (N - 1) + 1) / N**3
print(f"{res:.10f}")
