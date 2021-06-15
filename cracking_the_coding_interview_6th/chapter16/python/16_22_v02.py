from __future__ import annotations
from typing import MutableSet
from enum import Enum, auto


class Orientation(Enum):
    left = auto()
    right = auto()
    up = auto()
    down = auto()


class Pos:
    def __init__(self, row: int, col: int):
        self.row: int = row
        self.col: int = col

    def __eq__(self, other: Pos) -> bool:
        return self.row == other.row and self.col == other.col

    def __hash__(self) -> int:
        return hash((self.row, self.col))

    def __repr__(self) -> str:
        return f"({self.row}, {self.col})"


class Ant:
    def __init__(self):
        self.pos: Pos = Pos(0, 0)
        self.orientation: Orientation = Orientation.right

    def turn(self, clockwise: bool) -> None:
        if self.orientation is Orientation.left:
            self.orientation = Orientation.up if clockwise else Orientation.down
        elif self.orientation is Orientation.right:
            self.orientation = Orientation.down if clockwise else Orientation.up
        elif self.orientation is Orientation.up:
            self.orientation = Orientation.right if clockwise else Orientation.left
        else:
            self.orientation = Orientation.left if clockwise else Orientation.right

    def move(self) -> None:
        if self.orientation is Orientation.left:
            self.pos.col -= 1
        elif self.orientation is Orientation.right:
            self.pos.col += 1
        elif self.orientation is Orientation.up:
            self.pos.row -= 1
        else:
            self.pos.row += 1


class Board:
    def __init__(self):
        self.__topleft: Pos = Pos(0, 0)
        self.__btmright: Pos = Pos(0, 0)
        self.__black_cells: MutableSet[Pos] = set()
        self.__ant: Ant = Ant()

    def __flip(self, pos: Pos) -> None:
        if pos in self.__black_cells:
            self.__black_cells.remove(pos)
        else:
            self.__black_cells.add(Pos(pos.row, pos.col))   # Copy the pos obj

    def __ensure_fit(self, pos: Pos) -> None:
        self.__topleft.row = min(self.__topleft.row, pos.row)
        self.__topleft.col = min(self.__topleft.col, pos.col)

        self.__btmright.row = max(self.__btmright.row, pos.row)
        self.__btmright.col = max(self.__btmright.col, pos.col)

    def __is_black(self, pos: Pos) -> bool:
        return pos in self.__black_cells

    def move(self) -> None:
        self.__ant.turn(not self.__is_black(self.__ant.pos))
        self.__flip(self.__ant.pos)
        self.__ant.move()
        self.__ensure_fit(self.__ant.pos)

    def __repr__(self) -> str:
        res = []
        for i in range(self.__topleft.row, self.__btmright.row + 1):
            for j in range(self.__topleft.col, self.__btmright.col + 1):
                if self.__is_black(Pos(i, j)):
                    res.append('X')
                else:
                    res.append('_')
            res.append('\n')
        return ''.join(res)


def print_K_moves(K: int) -> None:
    board = Board()
    for _ in range(K):
        board.move()
    print(board)


def ns(f):
    return next(f).strip()


def solve(K: int):
    print(f"# K={K}")
    print_K_moves(K)
    print()


solve(3)
solve(5)
solve(10)
solve(20)
solve(50)

# # K=3
# _X
# XX


# # K=5
# __
# X_
# XX


# # K=10
# __X
# XXX
# XX_


# # K=20
# __X_
# _X_X
# ___X
# _XX_


# # K=50
# __XX__
# _X__X_
# X____X
# X_X__X
# _X_XX_
