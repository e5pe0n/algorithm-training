N = input()
if N == "1":
    print(0)
    exit()
fst = N[:(len(N) + 1)//2]
scnd = N[(len(N) + 1)//2:]
cnt = 0
for i in range(1, int(fst) + 1):
    if int(str(i) + str(i)) <= int(N):
        cnt += 1
print(cnt)
