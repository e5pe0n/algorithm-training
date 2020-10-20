MOD = 1_000_000_007


N = int(input())
A = map(int, input().split())

cc = 3
C = [0] * N
ans = 1
for a in A:
    if a == 0:
        ans *= cc
        cc -= 1
    else:
        ans *= C[a - 1]
        C[a - 1] -= 1
    C[a] += 1
ans %= MOD
print(ans)
