H, W = map(int, input().split())
N = int(input())
A = list(map(int, input().split()))

C = [[0] * W for _ in range(H)]
idx = 0
for i in range(H):
    if i % 2 == 0:
        for j in range(W):
            C[i][j] = idx
            A[idx] -= 1
            if A[idx] <= 0:
                idx += 1
    else:
        for j in range(W - 1, -1, -1):
            C[i][j] = idx
            A[idx] -= 1
            if A[idx] <= 0:
                idx += 1
print('\n'.join([' '.join(list(map(lambda x: str(x + 1), c))) for c in C]))
