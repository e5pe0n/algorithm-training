from typing import Iterable


class _List():
    class _El():
        def __init__(self, key):
            self.key = key
            self.nxt = self
            self.prv = self

        def __repr__(self):
            return f'(key: {self.key}, prv: {self.prv.key if self.prv != self else "None"},' \
                + f'nxt: {self.nxt.key if self.nxt != self else "None"})'

    def __init__(self, initializer: Iterable[int]):
        self.nil = self._El(-1)
        for i in initializer:
            self.list_insert(i)

    def __repr__(self):
        arr = []
        x = self.nil.nxt
        while x != self.nil:
            arr.append(x.key)
            x = x.nxt
        return repr(arr)

    def _list_insert(self, x):
        x.nxt = self.nil.nxt
        self.nil.nxt.prv = x
        self.nil.nxt = x
        x.prv = self.nil

    def list_insert(self, k: int):
        self._list_insert(self._El(k))

    def list_search(self, k: int):
        x = self.nil.nxt
        while x != self.nil and x.key != k:
            x = x.nxt
        return x

    def _list_delete(self, x):
        x.prv.nxt = x.nxt
        x.nxt.prv = x.prv

    def list_delete(self, k: int):
        x = self.list_search(k)
        if x != self.nil:
            self._list_delete(x)


def main():
    _list = _List([0, 1, 2])

    print(f'_list: {_list}')
    _list.list_insert(4)
    print(f'_list: {_list}')
    print(f'_list.list_search(2): {_list.list_search(2)}')
    print(f'_list.list_search(5): {_list.list_search(5)}')
    _list.list_delete(5)
    print(f'_list: {_list}')
    _list.list_delete(4)
    print(f'_list: {_list}')
    _list.list_delete(1)
    print(f'_list: {_list}')
    print(f'_list.list_search(1): {_list.list_search(1)}')


if __name__ == '__main__':
    main()
