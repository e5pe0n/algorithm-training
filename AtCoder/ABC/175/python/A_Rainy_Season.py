S = input()
res = 0
if S == 'RRR':
    res = 3
elif 'RR' in S:
    res = 2
elif 'R' in S:
    res = 1
print(res)
