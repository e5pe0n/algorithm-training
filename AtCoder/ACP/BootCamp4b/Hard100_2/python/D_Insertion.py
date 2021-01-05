N = int(input())
S = input()
left, right = 0, 0
for s in S:
    if s == '(':
        left += 1
    else:
        if left > 0:
            left -= 1
        else:
            right += 1
res = '(' * right + S + ')' * left
print(res)
