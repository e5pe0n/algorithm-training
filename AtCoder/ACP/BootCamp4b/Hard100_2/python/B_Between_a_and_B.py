a, b, x = map(int, input().split())
cnt_b = b // x
cnt_a = max(0, a - 1) // x
print(cnt_b - cnt_a + int(a == 0))
