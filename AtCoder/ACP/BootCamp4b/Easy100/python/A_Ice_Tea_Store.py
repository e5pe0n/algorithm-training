Q, H, S, D = list(map(int, input().split()))
N = int(input())
res = 0
if N >= 2:
    res += min(D, S * 2, H * 4, Q * 8) * (N // 2)
    N %= 2
if N >= 1:
    res += min(S, H * 2, Q * 4)
print(res)
