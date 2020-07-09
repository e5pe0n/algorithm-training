N, M = list(map(int, input().split()))
B = [True] * M
for i in range(N):
    A = list(map(int, input().split()))[1:]
    _B = [False] * M
    for a in A:
        _B[a - 1] = True
    B = list(map(lambda x: x[0] and x[1], zip(B, _B)))
print(sum(filter(lambda x: x, B)))
