class EmptyStackException(Exception):
    def __init__(self):
        self.msg = "stack is empty"
        super().__init__(self.msg)


class FullStackException(Exception):
    def __init__(self):
        self.msg = "stack is full"
        super().__init__(self.msg)


class FixedMultiStack:
    def __init__(self, size: int):
        self.num_of_stack = 3
        self.capacity = size
        self.vals = [0] * (self.capacity * self.num_of_stack)
        self.sizez = [0] * (self.num_of_stack)

    def push(self, stack_num: int, val: int):
        if self.is_full(stack_num):
            raise FullStackException()
        self.sizes[stack_num] += 1
        self.vals[self.idx_of_top(stack_num)] = val

    def pop(self, stack_num: int) -> int:
        if self.is_empty(stack_num):
            raise EmptyStackException()
        top_idx = self.idx_of_top(stack_num)
        val = self.vals[top_idx]
        self.vals[top_idx] = 0
        self.sizes[stack_num] -= 1
        return val

    def peek(self, stack_num: int) -> int:
        if self.is_empty(stack_num):
            raise EmptyStackException()
        return self.vals[self.idx_of_top(stack_num)]

    def is_empty(self, stack_num: int) -> bool:
        return self.sizes[stack_num] == 0

    def is_full(self, stack_num: int) -> bool:
        return self.sizes[stack_num] == self.capacity

    def idx_of_top(self, stack_num: int) -> int:
        offset = stack_num * self.capacity
        size = self.sizes[stack_num]
        return offset + size - 1
