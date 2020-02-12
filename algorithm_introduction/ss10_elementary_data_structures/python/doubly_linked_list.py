from typing import Iterable


class _List():
    class _El():
        def __init__(self, key: int):
            self.key = key
            self.prv = None
            self.nxt = None

        def __repr__(self):
            return f'(key: {self.key}, prv: {self.prv.key if self.prv else "None"}, '\
                + f'nxt: {self.nxt.key if self.nxt else "None"})'

    def __init__(self, initializer: Iterable[int]):
        self.head = None
        for i in initializer:
            self.list_insert(i)

    def __repr__(self):
        arr = []
        x = self.head
        while x is not None:
            arr.append(x.key)
            x = x.nxt
        return repr(arr)

    def list_search(self, k):
        x = self.head
        while x is not None and x.key != k:
            x = x.nxt
        return x

    def _list_insert(self, x):
        x.nxt = self.head
        if self.head is not None:
            self.head.prv = x
        self.head = x
        x.prv = None

    def list_insert(self, k):
        self._list_insert(self._El(k))

    def _list_delete(self, x):
        if x.prv is not None:
            x.prv.nxt = x.nxt
        else:
            self.head = x.nxt
        if x.nxt is not None:
            x.nxt.prv = x.prv

    def list_delete(self, k):
        x = self.list_search(k)
        if x is not None:
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
