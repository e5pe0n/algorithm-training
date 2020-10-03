S = input()
N = len(S)
S = S[::-1]
i = 0
T = ""
while i < N:
    if S[i] == 'r':
        T += "re"
        i += 2
        if i >= N:
            T += "0"
            break
        if S[i] == 'm':
            T += "maerd"
            i += 5
        elif S[i] == 's':
            T += "sare"
            i += 4
        else:
            T += "0"
            break
    elif S[i] == 'e':
        T += "esare"
        i += 5
    elif S[i] == 'm':
        T += "maerd"
        i += 5
    else:
        T += "0"
        break
if S == T:
    print("YES")
else:
    print("NO")
