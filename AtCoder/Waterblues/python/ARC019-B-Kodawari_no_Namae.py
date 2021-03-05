A = input()
N = len(A)
diff = 0
res = 0
left, right = 0, N - 1
while left <= right:
    if left == right:
        res += 25 * int(diff > 0)
    elif A[left] != A[right]:
        diff += 1
        res += 24 * 2
    else:
        res += 25 * 2
    left += 1
    right -= 1
if diff > 1:
    res += diff * 2
print(res)
