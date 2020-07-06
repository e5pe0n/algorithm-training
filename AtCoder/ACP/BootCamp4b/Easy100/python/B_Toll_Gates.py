N, M, X = list(map(int, input().split()))
A = list(map(int, input().split()))
left = 0
right = 0
for a in A:
    if a < X:
        left += 1
    else:
        right += 1
print(min(left, right))
