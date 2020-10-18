H, W, A, B = list(map(int, input().split()))
if A == 0 and B == 0:
    for i in range(H):
        print("".join(["1"] * W))
elif A == 0:
    for i in range(H):
        print("".join(["1" if i < B else "0" for _ in range(W)]))
elif B == 0:
    for i in range(H):
        print("".join(["1" if j < A else "0" for j in range(W)]))
else:
    for i in range(H):
        print("".join(["1" if (i < B and j < A) or (i >= B and j >= A) else "0" for j in range(W)]))
