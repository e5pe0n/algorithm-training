from typing import List


def solve(V: List[int]):
    V.sort()
    print(V[-3])


cases = {
    'case1': [4, 18, 25, 20, 9, 13],
    'case2': [95, 96, 97, 98, 99, 100],
    'case3': [19, 92, 3, 35, 78, 1]
}

for k, v in cases.items():
    solve(v)
