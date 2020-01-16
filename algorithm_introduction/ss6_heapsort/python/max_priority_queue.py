from collections import UserList
from typing import List


class MaxPriorityQueue(UserList):
    def __init__(self, initializer: List[int]):
        self.data = initializer
        self.last_heap_idx = len(initializer) - 1
        self._build_max_heap()

    def __str__(self) -> str:
        return str(self.data[:self.last_heap_idx + 1])

    def _parent(self, i: int):
        return (i - 1) >> 1

    def _left(self, i: int):
        return ((i + 1) << 1) - 1

    def _right(self, i: int):
        return (i + 1) << 1

    def _max_heapify(self, i: int):
        largest = i
        l = self._left(i)
        r = self._right(i)
        if l <= self.last_heap_idx and self[l] > self[largest]:
            largest = l
        if r <= self.last_heap_idx and self[r] > self[largest]:
            largest = r
        if largest != i:
            self[i], self[largest] = self[largest], self[i]
            self._max_heapify(largest)

    def _build_max_heap(self):
        for i in range((len(self) >> 1) - 1, -1, -1):
            self._max_heapify(i)

    def heap_maximum(self):
        return self[0]

    def heap_extract_max(self):
        if self.last_heap_idx < 0:
            raise ValueError('Heap underflow')
        max_val = self[0]
        self[0] = self[self.last_heap_idx]
        self.last_heap_idx -= 1
        self._max_heapify(0)
        return max_val

    def _heap_increase_key(self, i: int, key: int):
        if key < self[i]:
            raise ValueError(f'New key (={key}) must be greater than current key (={self[i]}).')
        self[i] = key
        while i > 0 and self[self._parent(i)] < self[i]:
            self[self._parent(i)], self[i] = self[i], self[self._parent(i)]
            i = self._parent(i)

    def max_heap_insert(self, key: int):
        self.last_heap_idx += 1
        self.append(-float('inf'))
        self._heap_increase_key(self.last_heap_idx, key)


def main():
    cases = {
        'A': MaxPriorityQueue([4, 1, 3, 2, 16, 9, 10, 14, 8, 7]),
        'B': MaxPriorityQueue([4, 1, 3, 2, 16, 9, 10, 14, 8]),
    }

    for k, v in cases.items():
        print(f'# {k}')
        print(v)
        print(v.heap_extract_max())
        print(v)
        print(v.heap_extract_max())
        print(v)
        print(v.heap_extract_max())
        print(v)
        print(v.heap_extract_max())
        print(v)
        v.max_heap_insert(100)
        print(v)
        v.max_heap_insert(6)
        print(v)
        print(v.heap_extract_max())
        print(v)
        print(v.heap_extract_max())
        print(v)
        print()


if __name__ == '__main__':
    main()
