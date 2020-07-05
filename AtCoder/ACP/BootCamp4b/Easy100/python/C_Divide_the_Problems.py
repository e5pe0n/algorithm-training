N = int(input())
D = list(map(int, input().split()))
D.sort()
res = D[(N - 1) // 2 + 1] - D[(N - 1) // 2]
print(res)
