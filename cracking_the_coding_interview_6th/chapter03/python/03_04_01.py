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


class EmptyQueueException(Exception):
    def __init__(self):
        super().__init__("queue is empty")


class FullQueueException(Exception):
    def __init__(self):
        super().__init__("queue is full")


class MyQueue:
    def __init__(self, capacity):
        self._capacity: int = capacity
        self._input: Stack = Stack(capacity)
        self._output: Stack = Stack(capacity)

    def __repr__(self) -> str:
        return "[" \
            + " ".join(list(map(lambda x: f"{x:2d}", self._input._v + self._output._v))) + "]"

    def __len__(self) -> int:
        return len(self._input) + len(self._output)

    def enqueue(self, x: int) -> None:
        if self.is_full():
            raise FullQueueException()
        self._input.push(x)

    def dequeue(self) -> int:
        if self.is_empty():
            raise EmptyQueueException()
        if self._output.is_empty():
            self.migrate()
        return self._output.pop()

    def peek(self) -> int:
        if self.is_empty():
            raise EmptyQueueException()
        if self._output.is_empty():
            self.migrate()
        return self._output.peek()

    def migrate(self) -> None:
        while not self._input.is_empty():
            self._output.push(self._input.pop())

    def is_full(self) -> bool:
        return len(self) == self._capacity

    def is_empty(self) -> bool:
        return len(self) == 0


mq = MyQueue(10)
for i in range(10, 20):
    mq.enqueue(i)
print(mq)
for i in range(10):
    print(mq.dequeue())
print(mq)
for i in range(50, 54):
    mq.enqueue(i)
print(mq)
for i in range(2):
    print(mq.dequeue())
print(mq)

# [10 11 12 13 14 15 16 17 18 19  0  0  0  0  0  0  0  0  0  0]
# 10
# 11
# 12
# 13
# 14
# 15
# 16
# 17
# 18
# 19
# [10 11 12 13 14 15 16 17 18 19 19 18 17 16 15 14 13 12 11 10]
# [50 51 52 53 14 15 16 17 18 19 19 18 17 16 15 14 13 12 11 10]
# 50
# 51
# [50 51 52 53 14 15 16 17 18 19 53 52 51 50 15 14 13 12 11 10]
