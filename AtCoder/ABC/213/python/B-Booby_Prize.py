N = int(input())
A = (list(map(int, input().split())))
A = sorted(list(zip(A, range(N))))
print(A[-2][1] + 1)
