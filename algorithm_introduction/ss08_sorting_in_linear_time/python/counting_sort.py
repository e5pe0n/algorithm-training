from array import array


def counting_sort(A: array, B: array, k: int):
    C = array('I', [0 for _ in range(k + 1)])
    for a in A:
        C[a] += 1
    for i in range(len(C) - 1):
        C[i + 1] += C[i]
    for a in A[::-1]:
        B[C[a] - 1] = a
        C[a] -= 1


def main():
    cases = {
        'X': {
            'org': array('I', [2, 5, 3, 0, 2, 3, 0, 3]),
            'k': 5,
        },
        'Y': {
            'org': array('I', [2, 5, 3, 0, 2, 3, 0, 3, 2]),
            'k': 5,
        }
    }

    cases['X']['res'] = array('I', [0 for _ in range(len(cases['X']['org']))])
    cases['Y']['res'] = array('I', [0 for _ in range(len(cases['Y']['org']))])

    for k, v in cases.items():
        print(f'# {k}')
        print(f'before: {v["org"]}')
        counting_sort(v['org'], v['res'], v['k'])
        print(f'after: {v["res"]}\n')


if __name__ == '__main__':
    main()
