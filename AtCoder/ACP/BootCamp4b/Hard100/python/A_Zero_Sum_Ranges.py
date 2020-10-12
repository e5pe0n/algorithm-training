MAX_A = 1_000_000_000


N = int(input())
S = [0]
for a in [int(x) for x in input().split()]:
    S.append(S[-1] + a)

S.sort()
S.append(S[N] + 1)
cnt = 1
ans = 0
for i in range(N + 1):
    if S[i] == S[i + 1]:
        cnt += 1
    else:
        ans += cnt * (cnt - 1) // 2
        cnt = 1
print(ans)
