from collections import Counter
N = int(input())
C = Counter([''.join(sorted(input())) for _ in range(N)])
print(sum(list(map(lambda x: x[1] * (x[1] - 1) // 2, C.most_common()))))
