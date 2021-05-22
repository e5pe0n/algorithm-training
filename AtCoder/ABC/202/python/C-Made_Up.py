from collections import Counter

N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(lambda x: int(x) - 1, input().split()))

CA = Counter(A)
res = 0
for c in C:
    res += CA[B[c]]
print(res)
