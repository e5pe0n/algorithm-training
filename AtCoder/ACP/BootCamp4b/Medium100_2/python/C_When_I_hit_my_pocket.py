K, A, B = map(int, input().split())
if K <= A - 1 or B <= A:
    res = K + 1
else:
    k = K - (A - 1)
    res = max(K + 1, A + (B - A) * (k // 2) + k % 2)
print(res)
