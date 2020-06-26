import re


P = re.compile(r'[0-9]{3}')


def solve(S: str):
    if P.fullmatch(S):
        print(2 * int(S))
    else:
        print('error')


cases = {
    'case1': '678',
    'case2': 'abc',
    'case3': '0x8'
}

for k, v in cases.items():
    print(f'[{k}]')
    solve(v)
    print()

# [case1]
# 1356

# [case2]
# error

# [case3]
# error
