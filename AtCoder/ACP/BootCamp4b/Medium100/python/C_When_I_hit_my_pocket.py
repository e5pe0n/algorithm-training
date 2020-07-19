K, A, B = list(map(int, input().split()))
if A >= B - 1 or A + 1 > K:
    res = K + 1
else:
    K -= A + 1
    t = int(K / 2)
    res = (t + 1) * B - t * A + K % 2
print(res)
