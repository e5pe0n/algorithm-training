N = int(input())
A = list(map(int, input().split()))
S = set()
_S = 0
for a in A:
    if a <= 399:
        S.add(0)
    elif 400 <= a <= 799:
        S.add(1)
    elif 800 <= a <= 1199:
        S.add(2)
    elif 1200 <= a <= 1599:
        S.add(3)
    elif 1600 <= a <= 1999:
        S.add(4)
    elif 2000 <= a <= 2399:
        S.add(5)
    elif 2400 <= a <= 2799:
        S.add(6)
    elif 2800 <= a <= 3199:
        S.add(7)
    else:
        _S += 1
print(max(1, len(S)), len(S) + _S)
