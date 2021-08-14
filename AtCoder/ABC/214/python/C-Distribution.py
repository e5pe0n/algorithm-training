INF = float('inf')
MAX_T = 10**9
N = int(input())
S = list(map(int, input().split()))
T = list(map(int, input().split()))

fastest_i = 0
fastest_t = MAX_T
for i, t in enumerate(T):
    if fastest_t >= t:
        fastest_t = t
        fastest_i = i

t = INF
res = [INF] * N
for i in range(N + 1):
    j = (i + fastest_i) % N
    t = min(t, T[j])
    res[j] = min(res[j], t)
    t += S[j]
print('\n'.join(map(str, res)))
