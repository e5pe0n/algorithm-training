n = int(input())
A = [int(x) for x in input().split()]

max_a = max(A)
half = max_a / 2.0
min_diff = max_a
k = 0
for a in A:
    if a == max_a:
        continue
    diff = abs(half - a)
    if diff < min_diff:
        k = a
        min_diff = diff
print(max_a, k)
