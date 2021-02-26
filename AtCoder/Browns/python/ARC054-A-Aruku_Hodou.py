L, X, Y, S, D = map(int, input().split())
d_cw = (D - S + L) % L
d_ccw = (S - D + L) % L
t_cw = d_cw / (Y + X)
t_ccw = -1 if Y - X == 0 else d_ccw / (Y - X)
res = min(t_cw, t_ccw)
if t_cw < 0:
    res = t_ccw
if t_ccw < 0:
    res = t_cw
print(f"{res:.7f}")
