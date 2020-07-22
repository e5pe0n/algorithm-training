MAX_S = 1_000_000_000
N, K, S = list(map(int, input().split()))
for _ in range(K):
    print(S, '', end='')
if S == MAX_S:
    for _ in range(K, N):
        print(1, '', end='')
else:
    for _ in range(K, N):
        print(MAX_S, '', end='')
print()
