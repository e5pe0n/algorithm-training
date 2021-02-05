S = input()
left = 0
right = len(S) - 1
res = 0
while left < right:
    if S[left] != S[right]:
        res += 1
    left += 1
    right -= 1
print(res)
