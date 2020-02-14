from array import array

array_size = 16
A = array('i', [-1 for _ in range(array_size)])

object_size = 3
key_offset = 0
nxt_offset = 1
prv_offset = 2
head = -1

max_idx = array_size - array_size % object_size - 1


def array_str() -> str:
    idxs_s = 'idxs: ['
    keys_s = 'keys: ['
    nxts_s = 'nxts: ['
    prvs_s = 'prvs: ['

    for i in range(0, max_idx + 1, object_size):
        idxs_s += f'{i:3d},'
        keys_s += f'{A[i]:3d},'
        nxts_s += f'{A[i + nxt_offset]:3d},'
        prvs_s += f'{A[i + prv_offset]:3d},'

    return '\n'.join([s + ']' for s in (idxs_s, keys_s, nxts_s, prvs_s)])


def array_search(key: int) -> int:
    for i in range(0, max_idx + 1, object_size):
        if A[i] == key:
            return i
    return -1


def find_free_pos() -> int:
    return array_search(-1)


def array_insert(key: int):
    global head

    pos = find_free_pos()
    if pos < 0:
        raise ValueError('Overflow')

    A[pos] = key
    A[pos + nxt_offset] = head
    A[pos + prv_offset] = -1

    if head >= 0:
        A[head + prv_offset] = pos
    head = pos


def array_delete(key: int):
    global head

    pos = array_search(key)
    if pos >= 0:
        if A[pos + prv_offset] >= 0:
            A[A[pos + prv_offset] + nxt_offset] = A[pos + nxt_offset]
        else:
            head = A[pos + nxt_offset]

        if A[pos + nxt_offset] >= 0:
            A[A[pos + nxt_offset] + prv_offset] = A[pos + prv_offset]

        A[pos] = -1


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
    print(f'head: {head}')
    print('\n')

    print('array_delete(12)')
    print(f'head: {head}')
    array_delete(12)
    print(array_str())
    print(f'head: {head}')
    print()

    print('array_delete(14)')
    print(f'head: {head}')
    array_delete(14)
    print(array_str())
    print(f'head: {head}')
    print()

    print(f'array_search(10): {array_search(10)}')
    print(f'array_search(12): {array_search(12)}')
    print(f'array_search(14): {array_search(14)}')

    print()

    print(f'head: {head}')
    array_insert(15)
    print(array_str())
    print(f'head: {head}')


if __name__ == '__main__':
    main()
