H, W = [int(x) for x in input().split()]
N = int(input())
A = [int(x) for x in input().split()]

B = [0 for _ in range(W)]
idx = 0
for i in range(H):
    for j in range(W):
        if A[idx] <= 0:
            idx += 1
        A[idx] -= 1
        if i % 2 == 0:
            B[j] = str(idx + 1)
        else:
            B[W - j - 1] = str(idx + 1)
    print(" ".join(B))
