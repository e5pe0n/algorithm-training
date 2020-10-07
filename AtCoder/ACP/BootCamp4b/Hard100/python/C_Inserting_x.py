s = input()
left = 0
right = len(s) - 1
cnt = 0
possible = True
while left <= right:
    if s[left] == s[right]:
        left += 1
        right -= 1
    elif s[left] != 'x' and s[right] == 'x':
        right -= 1
        cnt += 1
    elif s[left] == 'x' and s[right] != 'x':
        left += 1
        cnt += 1
    else:
        possible = False
        break
if possible:
    print(cnt)
else:
    print(-1)
