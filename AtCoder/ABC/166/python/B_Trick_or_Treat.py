N, K = map(int, input().split())
A = [[0] * K for _ in range(N)]
for i in range(K):
    d = int(input())
    a = list(map(int, input().split()))
    for _a in a:
        A[_a - 1][i] += 1


res = len(list(filter(lambda x: all(map(lambda y: y == 0, x)), A)))
print(res)
