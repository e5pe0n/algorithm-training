S = input()[::-1]
i = 0
N = len(S)
while i < N:
    if S[i] == 'e' and S[i:i + 5] == "esare":
        i += 5
    elif S[i] == 'm' and S[i:i + 5] == "maerd":
        i += 5
    elif S[i] == 'r' and S[i:i + 6] == "resare":
        i += 6
    elif S[i] == 'r' and S[i:i + 7] == "remaerd":
        i += 7
    else:
        print("NO")
        exit()
print("YES")
