from typing import Iterable
from collections import UserList


class CircularArray(UserList):
    def __init__(self, init: Iterable):
        self.data = list(init)
        self.offset = 0

    def __repr__(self) -> str:
        return repr(self.data)

    def __getitem__(self, key):
        return self.data[self.cidx(key)]

    def __setitem__(self, key, value):
        self.data[self.cidx(key)] = value

    def __iter__(self):
        for i in range(len(self)):
            yield self.data[(i + self.offset) % len(self)]

    def cidx(self, idx) -> int:
        return (idx + self.offset) % len(self)

    def __inc_offset(self):
        self.offset = (self.offset + 1) % len(self)

    def __dec_offset(self):
        self.offset = ((self.offset - 1) % len(self) + len(self)) % len(self)

    def rotate_left(self):
        self.__inc_offset()

    def rotate_right(self):
        self.__dec_offset()


ca = CircularArray([10, 11, 12, 13, 14])
for n in ca:
    print(f"{n} ", end='')
print()
# 10 11 12 13 14

ca.rotate_right()
for n in ca:
    print(f"{n} ", end='')
print()
# 14 10 11 12 13

ca.rotate_left()
ca.rotate_left()
ca.rotate_left()
for n in ca:
    print(f"{n} ", end='')
print()
# 12 13 14 10 11

for i in range(len(ca)):
    print(f"{ca[i]} ", end='')
print()
# 12 13 14 10 11

ca.append(100)
ca.append(200)
for n in ca:
    print(f"{n} ", end='')
print()
# 12 13 14 100 200 10 11

ca.pop()
for n in ca:
    print(f"{n} ", end='')
print()
# 12 13 14 100 10 11

ca[1] = 999
for n in ca:
    print(f"{n} ", end='')
print()
# 12 999 14 100 10 11
