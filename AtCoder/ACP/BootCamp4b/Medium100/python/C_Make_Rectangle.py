from collections import Counter
N = int(input())
A = list(map(int, input().split()))
C = Counter(A)
V = sorted([(k, v) for k, v in C.most_common() if v >= 2])
a = 0
b = 0
for v in V[::-1]:
    if a == 0:
        if v[1] >= 4:
            a, b = v[0], v[0]
            break
        else:
            a = v[0]
    else:
        b = v[0]
        break
print(a * b)
