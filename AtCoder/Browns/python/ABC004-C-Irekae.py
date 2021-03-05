N = int(input()) % 30
S = list("123456")
for i in range(N):
    left, right = i % 5, i % 5 + 1
    S[left], S[right] = S[right], S[left]
print(''.join(S))
