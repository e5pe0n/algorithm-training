N = int(input())
res = 0.0
for i in range(1, N):
    res += N / (N - i)
print(f"{res:.7f}")
