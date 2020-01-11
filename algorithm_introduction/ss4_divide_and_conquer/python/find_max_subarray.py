def find_max_crossing_subarray(A, low, mid, high):
    max_left_idx = mid
    left_sum = -float('inf')
    sum = 0
    for i in range(mid, low - 1, -1):
        sum += A[i]
        if sum > left_sum:
            left_sum = sum
            max_left_idx = i

    max_right_idx = mid + 1
    right_sum = -float('inf')
    sum = 0
    for j in range(mid + 1, high + 1):
        sum += A[j]
        if sum > right_sum:
            right_sum = sum
            max_right_idx = j
    return max_left_idx, max_right_idx, left_sum + right_sum


def find_maximum_subarray(A, low, high):
    if high == low:
        return low, high, A[low]
    else:
        mid = (low + high) // 2
        left_low_idx, left_high_idx, left_sum = find_maximum_subarray(A, low, mid)
        right_low_idx, right_high_idx, right_sum = find_maximum_subarray(A, mid + 1, high)
        cross_low_idx, cross_high_idx, cross_sum = find_max_crossing_subarray(A, low, mid, high)
        if left_sum >= right_sum and left_sum >= cross_sum:
            return left_low_idx, left_high_idx, left_sum
        elif right_sum >= left_sum and right_sum >= cross_sum:
            return right_low_idx, right_high_idx, right_sum
        else:
            return cross_low_idx, cross_high_idx, cross_sum


def main():
    cases = {
        'A': [13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7]
    }

    for k, v in cases.items():
        print(f'{k}: {v}')
        low_idx, high_idx, max_sum = find_maximum_subarray(v, 0, len(v) - 1)
        print(f'low_idx: {low_idx}, high_idx: {high_idx}, max_sum: {max_sum}\n')
        assert (low_idx, high_idx, max_sum) == (7, 10, 43)


if __name__ == '__main__':
    main()
