N, A, B = map(int, input().split())
S = [int(input()) for _ in range(N)]
if max(S) - min(S) == 0:
    print(-1)
    exit()
P = B / (max(S) - min(S))
Q = (N * A - P * sum(S)) / N
print(f"{P:.7f} {Q:.7f}")
