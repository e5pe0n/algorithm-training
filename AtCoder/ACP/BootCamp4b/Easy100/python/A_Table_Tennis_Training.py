N, A, B = list(map(int, input().split()))
if A % 2 == B % 2:
    print((B - A) // 2)
else:
    print(min((A + B) // 2, (N - A + 1 + N - B + 1) // 2))
