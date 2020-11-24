K = int(input())
if K % 2 == 0 or K % 5 == 0:
    print('-1')
    exit()
res = 0
t = 0
while True:
    for i in range(10):
        t += K * i
        if t % 10 == 7:
            res += 1
            t //= 10
            break
        t -= K * i
    if t == 0:
        break
print(res)
