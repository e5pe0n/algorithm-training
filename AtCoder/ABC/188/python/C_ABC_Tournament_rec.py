N = int(input())
N = 1 << N
A = list(map(int, input().split()))


def rec(left, right):
    if left == right:
        return left
    mid = (left + right) // 2
    left_res = rec(left, mid)
    right_res = rec(mid + 1, right)
    if left == 0 and right == N - 1:
        if A[left_res] > A[right_res]:
            return right_res
        else:
            return left_res
    if A[left_res] > A[right_res]:
        return left_res
    else:
        return right_res


print(rec(0, N - 1) + 1)
