N, K = map(int, input().split())
A = list(map(int, input().split()))
A = sorted([[A[i], i] for i in range(N)])
res = K // N
for i in range(N):
    A[i].append(res)
    if i < K % N:
        A[i][-1] += 1

A.sort(key=lambda x: x[1])
for a in A:
    print(a[2])
