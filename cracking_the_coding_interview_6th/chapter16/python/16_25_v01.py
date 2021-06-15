from __future__ import annotations
from typing import TypeVar, Generic
from collections import UserDict

T = TypeVar('T')


class EmptyListException(Exception):
    pass


class Node(Generic[T]):
    def __init__(self, key: int, value: T):
        self.key: int = key
        self.value: T = value
        self.prv: Node = None
        self.nxt: Node = None

    def __repr__(self) -> str:
        return f"({self.key}, {self.value})"


class LRUCache(Generic[T], UserDict):
    def __init__(self, capacity: int):
        if capacity <= 0:
            raise ValueError("capacity must be greater than 0.")
        super().__init__()
        self.__capacity: int = capacity
        self.__head: Node = None
        self.__tail: Node = None

    def __repr__(self) -> str:
        node = self.__head
        res = []
        while node is not None:
            res.append(repr(node))
            node = node.nxt
        return ' '.join(res)

    def __getitem__(self, key: int) -> T:
        if key not in self:
            raise KeyError(f"key={key} does not exist.")
        node = self.data[key]
        self.__touch(node)
        return node.value

    def __setitem__(self, key: int, value: T) -> None:
        node = Node(key, value)
        if key not in self and len(self) == self.__capacity:
            self.__del(self.__tail)
            self.__prepend(node)
            return
        self.__prepend(node)
        self.data[key] = node

    def __prepend(self, node: Node[T]) -> None:
        if self.__head is None:
            self.__head = self.__tail = node
            return
        h = self.__head
        self.__head = node
        self.__head.nxt = h
        h.prv = self.__head

    def __del(self, node: Node[T]) -> None:
        if self.__head is None:
            raise EmptyListException("list is empty.")
        if node is self.__head:
            self.__head = node.nxt
        if node is self.__tail:
            self.__tail = node.prv
        if node.nxt is not None:
            node.nxt.prv = node.prv
        if node.prv is not None:
            node.prv.nxt = node.nxt

    def __touch(self, node: Node[T]) -> None:
        if node is self.__head:
            return
        self.__del(node)
        self.__prepend(node)

    def get(self, key: int, default_value: T) -> T:
        try:
            return self[key]
        except KeyError:
            return default_value


c = LRUCache(5)
c[1] = "a"
c[2] = "b"
c[3] = "c"
print(c)    # (3, c) (2, b) (1, a)
c[1]
print(c)    # (1, a) (3, c) (2, b)
c[4] = "d"
c[5] = "e"
print(c)    # (5, e) (4, d) (1, a) (3, c) (2, b)
c[6] = "f"
print(c)    # (6, f) (5, e) (4, d) (1, a) (3, c)
c[7] = "g"
print(c)    # (7, g) (6, f) (5, e) (4, d) (1, a)
c[1]
c[8] = "h"
print(c)    # (8, h) (1, a) (7, g) (6, f) (5, e)
