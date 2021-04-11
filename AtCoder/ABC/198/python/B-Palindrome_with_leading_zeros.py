N = input()
front = 0
for n in N:
    if n != '0':
        break
    front += 1
back = 0
for n in N[::-1]:
    if n != '0':
        break
    back += 1
if front > back:
    print("No")
    exit()
N = N[front:len(N) - back]
left, right = 0, len(N) - 1
while left < right:
    if N[left] == N[right]:
        left += 1
        right -= 1
    else:
        print("No")
        exit()
print("Yes")
