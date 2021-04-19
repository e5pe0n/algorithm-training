from typing import List


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


def sort_stack(s: Stack):
    work = Stack(len(s))
    while not s.is_empty():
        x = s.pop()
        while not work.is_empty() and x < work.peek():
            s.push(work.pop())
        work.push(x)
    while not work.is_empty():
        s.push(work.pop())


s = Stack(10)
s.push(30)
s.push(80)
s.push(20)
s.push(40)
s.push(10)
s.push(70)
s.push(60)
s.push(50)
sort_stack(s)
while not s.is_empty():
    print(s.pop())

# 10
# 20
# 30
# 40
# 50
# 60
# 70
# 80
