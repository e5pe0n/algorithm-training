class EmptyStackException(Exception):
    def __init__(self):
        self.msg = "stack is empty"
        super().__init__(self.msg)


class FullStackException(Exception):
    def __init__(self):
        self.msg = "stack is full"
        super().__init__(self.msg)


class ThreeInOne:
    class Stack:
        def __init__(self, btm, size):
            self.pt = btm
            self.btm = btm
            self.size = size

    def __init__(self, each_size):
        self.v = [0] * (each_size * 3)
        self.s1 = self.Stack(0, each_size)
        self.s2 = self.Stack(each_size, each_size)
        self.s3 = self.Stack(each_size * 2, each_size)

    def __repr__(self):
        res = []
        res.append("[" + " ".join(list(map(lambda x: f"{x:2d}", self.v))) + "]")
        res.append("btm " + " ".join(
            list(map(lambda x: " ^" if x in (
                self.s1.btm, self.s2.btm, self.s3.btm
            ) else "  ", range(len(self.v))))
        ))
        res.append("pt  " + " ".join(
            list(map(lambda x: " ^" if x in (
                self.s1.pt, self.s1.pt, self.s2.pt
            ) else " ", range(len(self.v))))
        ))
        return "\n".join(res)

    def __len__(self) -> int:
        return len(self.v)

    def __pt(self, s: Stack) -> int:
        return s.pt + len(self) if s.pt < s.btm else s.pt

    def pop(self, s: Stack) -> int:
        if self.is_empty(s):
            raise EmptyStackException()
        s.pt = ((s.pt - 1) % len(self) + len(self)) % len(self)
        return self.v[s.pt]

    def push(self, s: Stack, x: int):
        if self.is_full(s):
            self.__modify(s)
        self.v[s.pt] = x
        s.pt = (s.pt + 1) % len(self)

    def peek(self, s: Stack) -> int:
        if self.is_empty(s):
            raise EmptyStackException()
        return self.v[s.pt - 1]

    def is_empty(self, s: Stack) -> bool:
        return s.pt == s.btm

    def is_full(self, s: Stack) -> bool:
        return self.__pt(s) >= s.size

    def are_all_full(self) -> bool:
        return (self.__pt(self.s1) - self.s1.btm) \
            + (self.__pt(self.s2) - self.s2.btm) \
            + (self.__pt(self.s3) - self.s3.btm) >= len(self)

    def __shift(self, s: Stack):
        for i in range(self.__pt(s), s.btm, -1):
            self.v[i % len(self)] = self.v[((i - 1) % len(self) + len(self)) % len(self)]
        s.btm = (s.btm + 1) % len(self)
        s.pt = (s.pt + 1) % len(self)

    def __shrink(self, s: Stack):
        self.__shift(s)
        s.size -= 1

    def __modify(self, target: Stack, nxt: Stack, nxt_nxt: Stack):
        if not self.is_full(nxt):
            self.__shrink(nxt)
        else:
            self.__shrink(nxt_nxt)
            self.__shift(nxt)
        target.size += 1
