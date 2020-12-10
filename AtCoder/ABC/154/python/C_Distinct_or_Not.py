N = int(input())
A = sorted(list(map(int, input().split())))
for i in range(N - 1):
    if A[i] == A[i + 1]:
        print("NO")
        exit()
print("YES")
