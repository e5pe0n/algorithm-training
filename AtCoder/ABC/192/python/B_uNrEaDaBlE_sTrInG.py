S = input()
f = True
for i, s in enumerate(S):
    if i % 2 == 0 and not s.islower():
        f = False
        break
    if i % 2 != 0 and not s.isupper():
        f = False
        break
if f:
    print("Yes")
else:
    print("No")
