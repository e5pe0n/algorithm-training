N, K, Q = list(map(int, input().split()))
A = [K] * N
for i in range(Q):
    a = int(input())
    A[a - 1] += 1
for i in range(N):
    if A[i] - Q <= 0:
        print('No')
    else:
        print('Yes')
