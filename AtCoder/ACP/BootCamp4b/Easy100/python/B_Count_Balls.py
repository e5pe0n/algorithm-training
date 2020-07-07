N, A, B = list(map(int, input().split()))
p = N // (A + B)
q = N % (A + B)
print(p * A + min(A, q))
