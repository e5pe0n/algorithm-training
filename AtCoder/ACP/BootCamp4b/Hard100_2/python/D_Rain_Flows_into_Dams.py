N = int(input())
A = list(map(int, input().split()))

res = sum([A[i] if i % 2 == 0 else -A[i] for i in range(N)])
print(res, '', end='')
for i in range(1, N):
    res = -res + A[i - 1] * 2
    print("%d%c" % (res, '\n' if i == N - 1 else ' '), end="", flush=True)
