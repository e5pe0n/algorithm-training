N, D, A = map(int, input().split())
XH = sorted([list(map(int, input().split())) for _ in range(N)])


X = [xh[0] for xh in XH]
H = [xh[1] for xh in XH]

left = 0
right = 1
R = [0] * N
while left < N:
    while right < N and X[right] - X[left] <= 2 * D:
        right += 1
    R[left] = right - 1
    left += 1

res = 0
sm = [0] * (N + 1)
for i in range(N - 1, -1, -1):
    d = max(0, H[i] - sm[i + 1] + sm[R[i] + 1])
    c = (d + A - 1) // A
    res += c
    sm[i] = sm[i + 1] + c * A
print(res)
