def ns(f):
    return next(f).strip()


with open("../testset/partial_sum/test2.txt") as f:
    N = int(ns(f))
    A = list(map(int, ns(f).split()))
    K = int(ns(f))


possible = False
for i in range(1, 1 << N):
    B = format(i, f"0{N}b")
    t = 0
    for j in range(N):
        if B[j] == "1":
            t += A[j]
    if t == K:
        possible = True
        break
if possible:
    print("Yes")
else:
    print("No")
