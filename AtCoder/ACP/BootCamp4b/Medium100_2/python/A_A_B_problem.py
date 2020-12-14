N, A, B = map(int, input().split())

res = max(0, (N - 1) * B + A - (B + (N - 1) * A) + 1)
print(res)
