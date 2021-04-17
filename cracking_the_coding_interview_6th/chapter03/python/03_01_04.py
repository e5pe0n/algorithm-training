class EmptyStackException(Exception):
    def __init__(self):
        self.msg = "stack is empty"
        super().__init__(self.msg)


class FullStackException(Exception):
    def __init__(self):
        self.msg = "stack is full"
        super().__init__(self.msg)


class MultiStack:
    class StackInfo:
        def __init__(self,
                     holder,  # MultiStack
                     start: int,
                     capacity: int
                     ):
            self.holder = holder
            self.start = start
            self.capacity = capacity
            self.size = 0

        def is_within_stack_capacity(self, idx: int) -> bool:
            if idx < 0 or idx >= len(self.holder.vals):
                return False
            contiguous_idx = idx + len(self.holder.vals) if idx < self.start else idx
            end = self.start + self.capacity
            return self.start <= contiguous_idx < end

        def last_capacity_idx(self) -> int:
            return self.holder.adjust_idx(self.start + self.capacity - 1)

        def last_elem_idx(self) -> int:
            return self.holder.adjust_idx(self.start + self.size - 1)

        def is_full(self) -> bool:
            return self.size == self.capacity

        def is_empty(self) -> bool:
            return self.size == 0

    def __init__(self, num_of_stacks, default_size):
        self.info = [self.StackInfo(self, default_size * i, default_size)
                     for i in range(num_of_stacks)]
        self.vals = [0] * (num_of_stacks * default_size)

    def push(self, stack_num: int, val: int):
        if self.all_stack_are_full():
            raise FullStackException()

        stack = self.info(stack_num)
        if stack.is_full():
            self.__expand(stack_num)

        stack.size += 1
        self.vals[stack.last_elem_idx()] = val

    def pop(self, stack_num: int) -> int:
        stack = self.info(stack_num)
        if stack.is_empty():
            raise EmptyStackException()

        val = self.vals[stack.last_elem_idx()]
        self.vals[stack.last_elem_idx()] = 0
        stack.size -= 1
        return val

    def peek(self, stack_num: int) -> int:
        stack = self.info[stack_num]
        return self.vals[stack.last_elem_idx()]

    def __shift(self, stack_num: int):
        stack = self.info[stack_num]

        if stack.size >= stack.capacity:
            nxt_stack = (stack_num + 1) % len(self.info)
            self.__shift(nxt_stack)
            stack.capacity += 1

        idx = stack.last_capacity_idx()
        while stack.is_within_stack_capacity(idx):
            self.vals[idx] = self.vals[self.__previous_idx(idx)]
            idx = self.__previous_idx(idx)

        self.vals[stack.start] = 0
        stack.start = self.__nxt_idx(stack.start)
        stack.capacity -= 1

    def expand(self, stack_num: int):
        self.__shift((stack_num + 1) % len(self.info))
        self.info[stack_num].capacity += 1

    def __num_of_elems(self) -> int:
        return sum(sd.size for sd in self.info)

    def __all_stacks_are_full(self) -> bool:
        return self.__num_of_elems() == len(self.vals)

    def __adjust_idx(self, idx: int):
        ma = len(self.vals)
        return ((idx % ma) + ma) % ma

    def __nxt_idx(self, idx: int) -> int:
        return self.__adjust_idx(idx + 1)

    def __previous_idx(self, idx: int) -> int:
        return self.__adjust_idx(idx - 1)
