from typing import List


class EmptyStackException(Exception):
    def __init__(self):
        super().__init__("stack is empty")


class FullStackException(Exception):
    def __init__(self):
        super().__init__("stack is full")


class Node:
    def __init__(self, value: int):
        self.value: int = value
        self.above = None   # Node
        self.below = None   # Node


class Stack:
    def __init__(self, capacity: int):
        self.__capacity = capacity
        self.top = None  # Node
        self.btm = None  # Node
        self.size: int = 0

    def is_full(self) -> bool:
        return self.size == self.__capacity

    def is_empty(self) -> bool:
        return self.size == 0

    def join(self, above: Node, below: Node):
        if below is not None:
            below.above = above
        if above is not None:
            above.below = below

    def push(self, x: int) -> bool:
        if self.size >= self.capacity:
            return False
        self.size += 1
        n = Node(x)
        if self.size == 1:
            self.btm = n
        self.join(n, self.top)
        self.top = n
        return True

    def pop(self) -> int:
        t = self.top
        self.top = self.top.below
        self.size -= 1
        return t.value

    def rm_btm(self) -> int:
        b = self.btm
        self.btm = self.btm.above
        if self.btm is not None:
            self.btm.below = None
        self.size -= 1
        return b.value


class SetOfStack:
    def __init__(self, capacity):
        self.capacity = capacity
        self.stacks: List[Stack] = []

    def get_last_stack(self) -> Stack:
        if len(self.stacks) == 0:
            return None
        return self.stacks[-1]

    def push(self, x: int):
        last = self.get_last_stack()
        if last is not None and not last.is_full():
            last.push(x)
        else:
            self.stacks.append(Stack(self.capacity))
            self.stacks[-1].push(x)

    def pop(self) -> int:
        last = self.get_last_stack()
        if last is None:
            raise EmptyStackException()
        x = last.pop()
        if last.is_empty():
            self.stacks.pop()
        return x

    def is_empty(self) -> bool:
        last = self.get_last_stack()
        return last is None or last.is_empty()

    def pop_at(self, idx: int) -> int:
        return self.left_shift(idx, True)

    def left_shift(self, idx: int, rm_top: bool) -> int:
        stack = self.stacks[idx]
        if rm_top:
            rmd_item = stack.pop()
        else:
            rmd_item = stack.rm_btm()
        if stack.is_empty():
            self.stacks.pop()
        elif len(self.stacks) > idx + 1:
            x = self.left_shift(idx + 1, False)
            stack.push(x)
        return rmd_item
