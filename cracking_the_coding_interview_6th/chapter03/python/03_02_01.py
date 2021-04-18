# Cracking the Coding Interview p.233
from typing import List


INF = float('inf')


class EmptyStackException(Exception):
    def __init__(self):
        super().__init__("stack is empty")


class FullStackException(Exception):
    def __init__(self):
        super().__init__("stack is full")


class Stack:
    def __init__(self, capacity: int):
        self._capacity: int = capacity
        self._v: List[int] = [0] * capacity
        self._pt: int = 0

    def __repr__(self):
        res = []
        res.append("  [" + " ".join(list(map(lambda x: f"{x:2d}", self._v))) + "]")
        res.append("pt " + " ".join(list(map(
            lambda x: " ^" if x == self._pt else "  ", range(len(self))
        ))))
        return "\n".join(res)

    def __len__(self) -> int:
        return len(self._v)

    def push(self, x: int) -> None:
        if self.is_full():
            raise FullStackException()
        self._v[self._pt] = x
        self._pt += 1

    def pop(self) -> int:
        if self.is_empty():
            raise EmptyStackException()
        self._pt -= 1
        return self._v[self._pt]

    def peek(self) -> int:
        if self.is_empty():
            raise EmptyStackException()
        return self._v[self._pt - 1]

    def is_empty(self) -> bool:
        return self._pt == 0

    def is_full(self) -> bool:
        return self._pt == self._capacity


class MinStack(Stack):
    def __init__(self, capacity):
        super().__init__(capacity)
        self.__mins: Stack = Stack(capacity)

    def push(self, x: int) -> None:
        if x <= self.min():
            self.__mins.push(x)
        super().push(x)

    def pop(self) -> int:
        x = super().pop()
        if x == self.min():
            self.__mins.pop()
        return x

    def min(self) -> int:
        return INF if self.__mins.is_empty() else self.__mins.peek()


ms = MinStack(10)
ms.push(5)
ms.push(3)
ms.push(7)
print(ms)
print(ms.min())
print()

ms.pop()
ms.pop()
print(ms)
print(ms.min())
print()

ms.push(7)
ms.push(3)
ms.push(9)
ms.push(1)
print(ms)
print(ms.min())
print()

for i in range(4):
    ms.pop()
    print(ms)
    print(ms.min())
    print()

print(ms)
print(ms.min())

#   [ 5  3  7  0  0  0  0  0  0  0]
# pt           ^
# 3

#   [ 5  3  7  0  0  0  0  0  0  0]
# pt     ^
# 5

#   [ 5  7  3  9  1  0  0  0  0  0]
# pt                 ^
# 1

#   [ 5  7  3  9  1  0  0  0  0  0]
# pt              ^
# 3

#   [ 5  7  3  9  1  0  0  0  0  0]
# pt           ^
# 3

#   [ 5  7  3  9  1  0  0  0  0  0]
# pt        ^
# 5

#   [ 5  7  3  9  1  0  0  0  0  0]
# pt     ^
# 5

#   [ 5  7  3  9  1  0  0  0  0  0]
# pt     ^
# 5
