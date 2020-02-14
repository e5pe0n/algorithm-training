from array import array

array_size = 5
head = -1

keys = array('i', [-1 for _ in range(array_size)])
prvs = array('i', [-1 for _ in range(array_size)])
nxts = array('i', [-1 for _ in range(array_size)])


def array_str():
    idxs_s = [f'{i:2d}' for i in range(array_size)]
    prvs_s = [f'{i:2d}' for i in prvs]
    keys_s = [f'{i:2d}' for i in keys]
    nxts_s = [f'{i:2d}' for i in nxts]
    return "\n".join([str(s) for s in (idxs_s, prvs_s, keys_s, nxts_s)])


def array_search(key: int) -> int:
    for i in range(array_size):
        if keys[i] == key:
            return i
    return -1


def find_free_pos() -> int:
    return array_search(-1)


def array_insert(key: int):
    global head

    pos = find_free_pos()
    if pos < 0:
        raise ValueError('Overflow')

    keys[pos] = key
    prvs[pos] = -1
    nxts[pos] = head

    if head >= 0:
        prvs[head] = pos
    head = pos


def array_delete(key: int):
    global head

    pos = array_search(key)
    if pos >= 0:
        if prvs[pos] >= 0:
            nxts[prvs[pos]] = nxts[pos]
        else:
            head = nxts[pos]
        if nxts[pos] >= 0:
            prvs[nxts[pos]] = prvs[pos]
        keys[pos] = -1


def main():
    array_insert(10)
    array_insert(11)
    array_insert(12)
    array_insert(13)
    array_insert(14)

    print(array_str())

    try:
        array_insert(15)
    except ValueError as err:
        print(err)

    print(f'array_search(10): {array_search(10)}')
    print(f'array_search(12): {array_search(12)}')
    print(f'array_search(14): {array_search(14)}')
    print(f'array_search(15): {array_search(15)}')

    print()

    print('array_delete(10)')
    print(f'head: {head}')
    array_delete(10)
    print(array_str())
    print('\n')

    print('array_delete(12)')
    print(f'head: {head}')
    array_delete(12)
    print(array_str())
    print()

    print('array_delete(14)')
    print(f'head: {head}')
    array_delete(14)
    print(array_str())
    print()

    print(f'array_search(10): {array_search(10)}')
    print(f'array_search(12): {array_search(12)}')
    print(f'array_search(14): {array_search(14)}')

    print()

    print(f'head: {head}')
    array_insert(15)
    print(f'head: {head}')
    print(array_str())


if __name__ == '__main__':
    main()
