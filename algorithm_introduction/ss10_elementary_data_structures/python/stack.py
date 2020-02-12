from array import array


class _Stack():
    def __init__(self, capacity):
        self._capacity = capacity
        self._arr = array('I', [0 for _ in range(self._capacity)])
        self._top = -1

    def _stack_empty(self):
        return self._top < 0

    def _push(self, x):
        if self._top + 1 == self._capacity:
            raise ValueError('Overflow')
        self._top += 1
        self._arr[self._top] = x

    def _pop(self):
        if self._stack_empty():
            raise ValueError('Underflow')
        self._top -= 1
        return self._arr[self._top + 1]


def main():
    S = _Stack(3)

    print(f'S._stack_empty(): {S._stack_empty()}')
    S._push(1)
    S._push(2)
    print(f'S._arr: {S._arr}')
    print(f'S._stack_empty(): {S._stack_empty()}')
    print(f'S._pop(): {S._pop()}')
    print(f'S._arr: {S._arr}')
    S._push(3)
    S._push(4)
    try:
        S._push(5)
    except ValueError as err:
        print(err)
    print(f'S._pop(): {S._pop()}')
    print(f'S._pop(): {S._pop()}')
    print(f'S._pop(): {S._pop()}')
    try:
        print(f'S._pop(): {S._pop()}')
    except ValueError as err:
        print(err)


if __name__ == '__main__':
    main()
