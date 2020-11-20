N = input()
t = sum(map(int, list(N)))
if t % 9 == 0:
    print('Yes')
else:
    print("No")
