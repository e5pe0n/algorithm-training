N = int(input())
T = list(map(int, input().split()))
t = sum(T)
M = int(input())
S = [list(map(int, input().split())) for _ in range(M)]
for s in S:
    print(t - T[s[0] - 1] + s[1])
