N = int(input())
B = list(map(lambda x: int(x) - 1, input().split()))


res = []
while len(B) > 0:
    f = False
    for j in range(len(B) - 1, -1, -1):
        if B[j] == j:
            B.pop(j)
            f = True
            res.append(str(j + 1))
            break
    if not f:
        print(-1)
        exit()
print('\n'.join(res[::-1]))
