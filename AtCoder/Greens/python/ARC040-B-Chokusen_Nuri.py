N, R = map(int, input().split())
S = input()
last = N - 1
while last >= 0 and S[last] == 'o':
    last -= 1
res = max(0, last - R + 1)
i = 0
while i <= last:
    if S[i] == 'o':
        i += 1
    else:
        res += 1
        i += R
print(res)
