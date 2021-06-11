from __future__ import annotations
from typing import List, Dict
from collections import defaultdict


class Coord:
    def __init__(self, x: float, y: float):
        self.x: float = x
        self.y: float = y

    def __lt__(self, other: Coord) -> bool:
        if self.x == other.x:
            if self.y < other.y:
                return -1
            elif self.y == other.y:
                return 0
            else:
                return 1
        elif self.x < other.x:
            return -1
        else:
            return 1


class Line:
    epsilon = 0.0001

    def __init__(self, p: Coord, q: Coord):
        self.slope = 0.0
        self.intercept = 0.0
        self.infinite_slope = False
        if abs(p.x - q.x) > self.epsilon:
            self.slope = (p.y - q.y) / (p.x - q.x)
            self.intercept = p.y - self.slope * p.x
        else:
            self.infinite_slope = True
            self.intercept = p.x

    @classmethod
    def floor_to_nearest_epsilon(cls, d: float) -> float:
        return d // cls.epsilon * cls.epsilon

    @classmethod
    def is_equivalent(cls, a: float, b: float) -> bool:
        return abs(a - b) < cls.epsilon

    def __eq__(self, other: Line) -> bool:
        return self.is_equivalent(self.slope, other.slope) \
            and self.is_equivalent(self.intercept, other.intercept) \
            and self.infinite_slope == other.infinite_slope

    def __repr__(self) -> str:
        if self.infinite_slope:
            return f"1.0x + 0.0y + {-self.intercept} = 0"
        else:
            return f"{-self.slope}x + 1.0y + {-self.intercept} + 0 = 0"


def cnt_equivalent_lines_in_list(lines: List[Line], line: Line) -> int:
    return len(list(filter(lambda x: x == line, lines)))


def cnt_equivalent_lines(lines_by_slope: Dict[float, List[Line]], line: Line) -> int:
    key = Line.floor_to_nearest_epsilon(line.slope)
    cnt = cnt_equivalent_lines_in_list(lines_by_slope[key], line)
    cnt += cnt_equivalent_lines_in_list(lines_by_slope[key - Line.epsilon], line)
    cnt += cnt_equivalent_lines_in_list(lines_by_slope[key + Line.epsilon], line)
    return cnt


def get_best_line(lines_by_slope: Dict[float, List[Line]]) -> Line:
    best_line = Line(Coord(0, 0), Coord(0, 0))
    best_cnt = 0
    for slope, lines in lines_by_slope.items():
        for line in lines:
            cnt = cnt_equivalent_lines(lines_by_slope, line)
            if cnt > best_cnt:
                best_line = line
                best_cnt = cnt
    return best_line


def get_list_of_lines(coords: List[Coord]) -> Dict[float, List[Line]]:
    lines_by_slope = defaultdict(list)
    for i in range(len(coords)):
        for j in range(i + 1, len(coords)):
            line = Line(coords[i], coords[j])
            key = Line.floor_to_nearest_epsilon(line.slope)
            lines_by_slope[key].append(line)
    return lines_by_slope


def find_best_line(coords: List[Coord]) -> Line:
    lines_by_slope = get_list_of_lines(coords)
    return get_best_line(lines_by_slope)


def ns(f):
    return next(f).strip()


def solve(fp: str):
    print(f"# {fp}")
    with open(fp) as f:
        n = int(ns(f))
        coords = [Coord(*map(int, ns(f).split())) for _ in range(n)]
    coords.sort()
    res = find_best_line(coords)
    print(res)
    print()
