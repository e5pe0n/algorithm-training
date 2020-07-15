MAX_A = 100_001
N = int(input())
A = list(map(int, input().split()))
_A = [0] * MAX_A
for a in A:
    _A[a] += 1
    if a - 1 >= 0:
        _A[a - 1] += 1
    if a + 1 < MAX_A:
        _A[a + 1] += 1
print(max(_A))
