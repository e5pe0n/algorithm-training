g = 10.0


def ns(f):
    return next(f).strip()


with open("../testset/elastic_collision/test2.txt", 'r') as f:
    N, H, R, T = map(int, ns(f).split())


def calc(t):
    if t <= 0:
        return H
    _t = (2.0 * H / g) ** 0.5
    k = int(t / _t)
    if k % 2 == 0:
        dt = t - k * _t
    else:
        dt = (k + 1) * _t - t
    return H - g * dt * dt / 2.0


y = list(map(lambda i: calc(T - i), range(N)))
y.sort()
print(" ".join(list(map(lambda i: f"{y[i] + 2.0 * R * i / 100.0:.2f}", range(N)))))
