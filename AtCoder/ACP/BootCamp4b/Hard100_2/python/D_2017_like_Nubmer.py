MAX_R = 10**5
is_prime = [False] * 2 + [True] * MAX_R
for i in range(2, MAX_R + 1):
    if is_prime[i]:
        for j in range(i + i, MAX_R + 1, i):
            is_prime[j] = False

sm = [0] * (MAX_R + 2)
for i in range(1, MAX_R + 1):
    sm[i + 1] = sm[i] + int(i % 2 != 0 and is_prime[i] and is_prime[(i + 1) // 2])

Q = int(input())
res = [0] * Q
for i in range(Q):
    L, R = map(int, input().split())
    res[i] = sm[R + 1] - sm[L]
print('\n'.join(list(map(str, res))))
