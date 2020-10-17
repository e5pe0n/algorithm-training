# TLE
N = int(input())
A = [int(x) - i for i, x in enumerate(input().split(), 1)]
A.sort()
_min_a = A[0]
A = list(map(lambda x: x - _min_a, A))
sum_a = sum(A)
min_a = A[0]
max_a = A[-1]
n = N
_n = 0
_sum_a = 0
idx = 0
ans = sum_a
for b in range(min_a, max_a + 1):
    remain_plus = sum_a - n * b
    remain_minus = _n * b - _sum_a
    ans = min(ans, remain_plus + remain_minus)
    while b == A[idx] and b != max_a:
        n -= 1
        _n += 1
        sum_a -= A[idx]
        _sum_a += A[idx]
        idx += 1
print(ans)
