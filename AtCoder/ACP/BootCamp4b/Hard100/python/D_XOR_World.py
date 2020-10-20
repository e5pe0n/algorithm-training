import sys


A, B = map(int, input().split())
if A == B:
    print(A)
    sys.exit()
ans = 0
if A % 2 != 0:
    ans += A
    A += 1
q = (B - A + 1) % 4
for i in range(1, q + 1):
    ans ^= B - q + i
print(ans)
