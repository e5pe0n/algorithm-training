from array import array


class _Queue():
    # To distinguish between underflow and overflow, _Queue have an empty element in arr.
    # i.e. arr whose capacity is _capacity needs size which is _capacity + 1.
    def __init__(self, capacity):
        self._capacity = capacity
        self._size = self._capacity + 1
        self._arr = array('I', [0 for _ in range(self._size)])
        self._head = 0
        self._tail = 0

    def _queue_empty(self) -> bool:
        return self._head == self._tail

    def _queue_full(self) -> bool:
        tail_next = self._tail + 1
        if tail_next == self._size:
            tail_next = 0
        return tail_next == self._head

    def _enqueue(self, x: int):
        if self._queue_full():
            raise ValueError('Overflow')
        self._arr[self._tail] = x
        self._tail += 1
        if self._tail == self._size:
            self._tail = 0

    def _dequeue(self):
        if self._queue_empty():
            raise ValueError('Underflow')
        x = self._arr[self._head]
        self._head += 1
        if self._head == self._size:
            self._head = 0
        return x


def main():
    Q = _Queue(3)

    try:
        Q._dequeue()
    except ValueError as err:
        print(err)

    Q._enqueue(1)
    Q._enqueue(2)
    Q._enqueue(3)
    try:
        Q._enqueue(4)
    except ValueError as err:
        print(err)

    print(f'Q._arr: {Q._arr}')
    print(f'Q._dequeue(): {Q._dequeue()}')
    print(f'Q._arr: {Q._arr}')
    Q._enqueue(5)
    print(f'Q._arr: {Q._arr}')
    print(f'Q._dequeue(): {Q._dequeue()}')
    print(f'Q._arr: {Q._arr}')
    Q._enqueue(6)
    print(f'Q._arr: {Q._arr}')
    print(f'Q._dequeue(): {Q._dequeue()}')


if __name__ == '__main__':
    main()
