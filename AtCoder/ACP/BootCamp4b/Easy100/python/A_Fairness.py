MAX_N = 1_000_000_000_000_000_000
A, B, C, K = list(map(int, input().split()))
res = A - B if K % 2 == 0 else B - A
if abs(res) >= MAX_N:
    print('Unfair')
else:
    print(res)
