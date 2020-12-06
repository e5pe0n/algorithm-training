X = int(input())
res = X // 500 * 1000 + ((X - X // 500 * 500) // 5) * 5
print(res)
