from array import array


array_size = 5
keys = array('i', range(array_size))
nxts = array('i', range(array_size))
prvs = array('i', range(array_size))

head = -1
free = 0


def array_initialize():
    for i in range(array_size):
        keys[i] = -1
        nxts[i] = i + 1
        prvs[i] = i - 1

    nxts[array_size - 1] = -1


def array_str():
    idxs_s = "idxs: ["
    keys_s = "keys: ["
    nxts_s = "nxts: ["
    prvs_s = "prvs: ["

    for i in range(array_size):
        idxs_s += f'{i:2d}, '
        keys_s += f'{keys[i]:2d}, '
        nxts_s += f'{nxts[i]:2d}, '
        prvs_s += f'{prvs[i]:2d}, '

    return '\n'.join([s + "]" for s in (idxs_s, keys_s, nxts_s, prvs_s)])


def allocate_object() -> int:
    global free

    if free == -1:
        raise ValueError('Out of memory')
    else:
        pos = free
        free = nxts[pos]
        return pos


def free_object(pos: int):
    global free

    nxts[pos] = free
    free = pos


def array_search(key: int) -> int:
    for i in range(array_size):
        if keys[i] == key:
            return i
    return -1


def array_insert(key: int):
    global head

    try:
        pos = allocate_object()
    except ValueError as err:
        raise ValueError('Insertion failed: ' + str(err))

    keys[pos] = key
    nxts[pos] = head
    prvs[pos] = -1

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

        keys[pos] = -1  # for debug
        free_object(pos)


def main():
    array_initialize()

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
