S = input()


def is_palindrome(left, right):
    while left <= right:
        if S[left] != S[right]:
            return False
        left += 1
        right -= 1
    return True


N = len(S)
res = is_palindrome(0, N - 1) and is_palindrome(0, (N - 1) // 2 -
                                                1) and is_palindrome((N + 3) // 2 - 1, N - 1)
if res:
    print("Yes")
else:
    print("No")
