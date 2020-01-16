from collections import UserList
from typing import List


class MaxPriorityQueue(UserList):
    def __init__(self, initializer: List[int]):
        self.data = initializer
        self.last_heap_idx = len(initializer) - 1


A = MaxPriorityQueue([0, 1, 2])
print(A)
A[0] = 100
