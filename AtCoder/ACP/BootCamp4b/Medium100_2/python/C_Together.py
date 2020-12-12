from collections import Counter
N = int(input())
A = list(map(int, input().split()))

res = Counter(A + list(map(lambda x: x - 1, A)) + list(map(lambda x: x + 1, A))).most_common(1)[0][1]
print(res)
