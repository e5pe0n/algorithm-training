S = input()
left = 0
right = len(S) - 1
res = 0
while left < right:
    if S[left] == S[right]:
        left += 1
        right -= 1
    else:
        if S[left] == 'x':
            left += 1
            res += 1
        elif S[right] == 'x':
            right -= 1
            res += 1
        else:
            res = -1
            break
print(res)
