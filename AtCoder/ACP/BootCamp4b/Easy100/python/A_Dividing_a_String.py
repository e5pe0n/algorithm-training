S = input()
A = [S[0]]
a = ""
for s in S[1:]:
    a += s
    if a != A[-1]:
        A.append(a)
        a = ""
print(len(A))
