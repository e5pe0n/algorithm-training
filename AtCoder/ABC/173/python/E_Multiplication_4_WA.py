INF = float('inf')
MOD = int(1e9) + 7
N, K = map(int, input().split())
A = list(map(int, input().split()))

neg = [a for a in A if a < 0]
pos = [a for a in A if a > 0]
if len(pos) + len(neg) < K:
    print(0)
    exit()

neg.sort()
pos.sort()
abs_neg = [0]
abs_pos = [0]
mul_neg = [1]
mul_pos = [1]
for n in neg:
    abs_neg.append(abs_neg[-1] + abs(n))
    mul_neg.append(mul_neg[-1] * n % MOD)
for n in pos[::-1]:
    abs_pos.append(abs_pos[-1] + n)
    mul_pos.append(mul_pos[-1] * n % MOD)

res = 1
max_t = -INF
n_neg = len(abs_neg)
n_pos = len(abs_pos)
for i in range(K // 2 + 1):
    i_pos = K - i * 2
    i_neg = i * 2
    if 0 <= i_pos < n_pos and 0 <= i_neg < n_neg:
        t = abs_pos[i_pos] + abs_neg[i_neg]
        if t > max_t:
            max_t = t
            res = mul_pos[i_pos] * mul_neg[i_neg] % MOD
if max_t == -INF:
    k = 0
    i_neg = len(neg) - 1
    i_pos = 0
    while k < K and i_neg >= 0 and i_pos < len(pos):
        if abs(neg[i_neg]) < abs(pos[i_pos]):
            res = res * neg[i_neg] % MOD
            i_neg -= 1
        else:
            res = res * pos[i_pos] % MOD
            i_pos += 1
        k += 1
    while k < K and i_neg < 0:
        res = res * pos[i_pos] % MOD
        i_pos += 1
        k += 1
    while k < K and i_pos >= len(pos):
        res = res * neg[i_neg] % MOD
        i_neg -= 1
        k += 1
print((res + MOD) % MOD)
