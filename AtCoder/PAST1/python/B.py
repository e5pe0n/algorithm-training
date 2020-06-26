from typing import List


def solve(V: List[int]):
    N = V[0]
    A = V[1:]

    for i in range(N - 1):
        diff = A[i + 1] - A[i]
        if diff == 0:
            print('stay')
        elif diff < 0:
            print('down %d' % abs(diff))
        else:
            print('up %d' % diff)


v = [10, 9, 10, 3, 100, 100, 90, 80, 10, 30, 10]
solve(v)

# up 1
# down 7
# up 97
# stay
# down 10
# down 10
# down 70
# up 20
# down 20
