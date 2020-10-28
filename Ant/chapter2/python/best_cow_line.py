def ns(f):
    return next(f).strip()


with open("../testset/best_cow_line/test1.txt", 'r') as f:
    N = int(ns(f))
    S = ns(f)
T = ""
left_idx, right_idx = 0, N - 1
while left_idx <= right_idx:
    s = S[left_idx:right_idx + 1]
    if s < s[::-1]:
        T += S[left_idx]
        left_idx += 1
    else:
        T += S[right_idx]
        right_idx -= 1
print(T)
