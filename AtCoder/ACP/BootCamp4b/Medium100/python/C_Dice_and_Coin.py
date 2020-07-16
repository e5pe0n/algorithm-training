import math
N, K = list(map(int, input().split()))
res = 0
for i in range(1, min(N + 1, K)):
    res += math.pow(0.5, math.ceil(math.log2(math.ceil(K / i)))) / N
print(f'{res + max(0, (N - K + 1) / N):.10f}')
