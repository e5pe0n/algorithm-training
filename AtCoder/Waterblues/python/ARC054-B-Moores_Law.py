MIN_X = 0.0
MAX_X = 1e9
P = float(input())


def ternary_search(f, left, right, itr=500):
    for _ in range(itr):
        left_third = left + (right - left) / 3
        right_third = right - (right - left) / 3

        if f(left_third) > f(right_third):
            left = left_third
        else:
            right = right_third
    return (left + right) / 2


def f(x):
    return x + P * (2**(-x/1.5))


x = ternary_search(f, MIN_X, MAX_X)
print(f"{f(x):.9f}")
