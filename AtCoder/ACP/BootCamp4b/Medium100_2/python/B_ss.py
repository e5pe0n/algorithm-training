S = input()
N = len(S) - 2
while N > 0:
    if S[:N // 2] == S[N // 2:N]:
        break
    N -= 2
print(N)
