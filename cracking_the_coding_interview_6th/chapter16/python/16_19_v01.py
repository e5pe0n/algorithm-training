from typing import List
from collections import deque


def valid_range(row: int, col: int, height: int, width: int) -> bool:
    return 0 <= row < height and 0 <= col < width


def pond_area(mat: List[List[int]], row: int, col: int, used: List[bool]) -> int:
    q = deque([(row, col)])
    used[row][col] = True
    area = 1
    while q:
        x, y = q.popleft()
        for dx in range(-1, 2):
            for dy in range(-1, 2):
                _x = x + dx
                _y = y + dy
                if valid_range(_x, _y, len(mat), len(mat[0])) \
                        and mat[_x][_y] == 0 and not used[_x][_y]:
                    used[_x][_y] = True
                    area += 1
                    q.append((_x, _y))
    return area


def pond_areas(mat: List[List[int]]) -> List[int]:
    height, width = len(mat), len(mat[0])
    used = [[False] * width for _ in range(height)]
    areas = []
    for i in range(height):
        for j in range(width):
            if mat[i][j] == 0 and not used[i][j]:
                areas.append(pond_area(mat, i, j, used))
    return areas


def ns(f):
    return next(f).strip()


def solve(fp: str):
    print(f"# {fp}")
    with open(fp) as f:
        height, width = map(int, ns(f).split())
        mat = [list(map(int, list(ns(f)))) for _ in range(height)]
    res = pond_areas(mat)
    print(res)
    print()


solve("../testcases/16_19/01.txt")
solve("../testcases/16_19/02.txt")

# # ../testcases/16_19/01.txt
# [2, 4, 1]

# # ../testcases/16_19/02.txt
# [1, 10, 4, 12, 16, 2, 1, 18]
