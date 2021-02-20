N, K = map(int, input().split())
R = sorted(list(map(int, input().split())))[N-K:]

C = 0.0
for r in R:
    C = 0.5 * (r + C)
print(f"{C:.7f}")
