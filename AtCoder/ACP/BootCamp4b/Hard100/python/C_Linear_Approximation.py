N = int(input())
A = sorted([int(x) - i for i, x in enumerate(input().split(), 1)])
mid = N // 2
ans = sum(list(map(lambda x: abs(x - A[mid]), A)))
if N % 2 == 0:
    _mid = N // 2 + 1
    _ans = sum(list(map(lambda x: abs(x - A[_mid]), A)))
    ans = min(ans, _ans)
print(ans)
