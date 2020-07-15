from collections import Counter
N = int(input())
C = Counter([int(input()) for _ in range(N)])
print(len(list(filter(lambda x: x % 2 == 1, list(C.values())))))
