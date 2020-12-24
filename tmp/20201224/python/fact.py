def fact(n):
    res = 1
    for i in range(n, 0, -1):
        res *= i
    return res


print(fact(0))  # 1
print(fact(5))  # 120
print(fact(19))
print(fact(20))
print(fact(21))
