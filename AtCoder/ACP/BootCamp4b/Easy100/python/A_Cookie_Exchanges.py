import sys
A, B, C = list(map(int, input().split()))
if A % 2 != 0 or B % 2 != 0 or B % 2 != 0:
    print('0')
    sys.exit()
if A == B == C:
    print('-1')
    sys.exit()
cnt = 0
while A % 2 == 0 and B % 2 == 0 and C % 2 == 0:
    _A = A
    _B = B
    _C = C
    A = _B // 2 + _C // 2
    B = _A // 2 + _C // 2
    C = _A // 2 + _B // 2
    cnt += 1
print(cnt)
