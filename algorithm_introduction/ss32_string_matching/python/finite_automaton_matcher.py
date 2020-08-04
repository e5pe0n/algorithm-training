from typing import List


def compute_transition_function(P: str, S: List[str]) -> List[str]:
    m = len(P)
    D = [[0] * (m + 1) for _ in range(len(S))]
    for q in range(m + 1):
        for a in S:
            Pqa = P[:q] + a
            Pk = P
            while len(Pk) > 0 and Pk != Pqa[max(0, len(Pqa) - len(Pk)):max(0, len(Pqa) - len(Pk)) + len(Pk)]:
                Pk = Pk[:-1]
            D[ord(a) - ord('a')][q] = len(Pk)
    return D


def finite_automaton_matcher(T: str, D: List[List[int]], m: int):
    q = 0
    for i, t in enumerate(T):
        q = D[ord(t) - ord('a')][q]
        if q == m:
            print('Pattern occured at shirt', i + 1 - m)


T = 'abababacaba'
P = 'ababaca'
S = ['a', 'b', 'c']
D = compute_transition_function(P, S)
print('transition function D:')
print(D)
print()
finite_automaton_matcher(T, D, len(P))

# transition function D:
# [[1, 1, 3, 1, 5, 1, 7, 1], [0, 2, 0, 4, 0, 4, 0, 2], [0, 0, 0, 0, 0, 6, 0, 0]]

# Pattern occured at shirt 2
