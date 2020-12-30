S = input()
T = input()
CS = {}
CT = {}
f = True
for i in range(len(S)):
    if S[i] in CS and CS[S[i]] != T[i]:
        f = False
        break
    else:
        CS[S[i]] = T[i]
    if T[i] in CT and CT[T[i]] != S[i]:
        f = False
        break
    else:
        CT[T[i]] = S[i]
if f:
    print("Yes")
else:
    print("No")
