def com(n, k):
    if k == 0:  # nC0 = 1
        return 1
    x = 1
    for i in range(n, n - k, -1):   # 分子
        x *= i
    y = 1
    for i in range(k, 0, -1):   # 分母
        y *= i
    return x // y


print(com(5, 0))    # 1
print(com(5, 2))    # 10
