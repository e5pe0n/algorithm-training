# Cracking the Coding Interview p.271
import random


class Node:
    def __init__(self, data: int):
        self.__data: int = data
        self.__size: int = 0
        self.__left = None  # Node
        self.__right = None  # Node

    @property
    def size(self) -> int:
        return self.__size

    @property
    def data(self) -> int:
        return self.__data

    def get_ith_node(self, i: int):   # -> Node
        left_size = self.left.size if self.left else 0
        if i < left_size:
            return self.left.get_ith_node(i)
        elif i == left_size:
            return self.left
        else:
            return self.right.get_ith_node(i - (left_size + 1))

    def insert_in_order(self, d: int) -> None:
        if d <= self.__data:
            if not self.left:
                self.left = Node(d)
            else:
                self.left.insert_in_order(d)
        else:
            if not self.right:
                self.right = Node(d)
            else:
                self.right.insert_in_order(d)
        self.__size += 1

    def find(self, d: int):  # -> Node
        if d == self.__data:
            return self
        elif d <= self.__data:
            return self.left.find(d) if self.left else None
        elif d > self.__data:
            return self.right.find(d) if self.right else None
        return None


class Tree:
    def __init__(self):
        self.root: Node = None

    @property
    def size(self) -> int:
        return self.root.size if self.root else 0

    def get_random_node(self) -> Node:
        if not self.root:
            return None
        x = int(random.uniform(0, self.size - 1))
        return self.root.get_ith_node(x)

    def insert_in_order(self, value: int) -> None:
        if not self.root:
            self.root = Node(value)
        else:
            self.root.insert_in_order(value)
