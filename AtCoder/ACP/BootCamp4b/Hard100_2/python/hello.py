N = int(input())


def com(n, k):
    if n < 0 or k < 0 or k > n:
        return 0
    if k == 0:
        return 1
    res = 1
    for i in range(1, k + 1):
        res = res * (n - i + 1) // i
    return res


print(f"6C2={com(6, 2)}")   # 15
print(f"6C0={com(6, 0)}")   # 1
print(f"6C8={com(6, 8)}")   # 0
