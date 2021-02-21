N = int(input())
D = [int(input()) for _ in range(N)]
res_ma = sum(D)
ma = max(D)
remain = res_ma - ma
res_mi = max(0, ma - remain)
print(res_ma)
print(res_mi)
