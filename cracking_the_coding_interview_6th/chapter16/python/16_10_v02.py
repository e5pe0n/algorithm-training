from typing import List


class Person:
    def __init__(self, birth, dead):
        self.birth = birth
        self.dead = dead


def get_population_deltas(people: List[Person], mi: int, ma: int) -> List[int]:
    population_deltas = [0] * (ma - mi + 2)
    for p in people:
        population_deltas[p.birth - mi] += 1
        population_deltas[p.dead + 1 - mi] -= 1
    return population_deltas


def get_max_alive_year(deltas: List[Person]) -> int:
    max_alive_year = 0
    max_alive = 0
    curr_alive = 0
    for year in range(len(deltas)):
        curr_alive += deltas[year]
        if curr_alive > max_alive:
            max_alive_year = year
            max_alive = curr_alive
    return max_alive_year


def max_alive_year(people: List[Person], mi: int, ma: int) -> int:
    population_deltas = get_population_deltas(people, mi, ma)
    res = get_max_alive_year(population_deltas)
    return res + mi


def ns(f):
    return next(f).strip()


def solve(fp: str):
    print(f"# {fp}")
    with open(fp) as f:
        n = int(ns(f))
        people = []
        for _ in range(n):
            people.append(Person(*map(int, ns(f).split())))
    print(max_alive_year(people, 1900, 2000))
    print()


solve("../testcases/16_10/01.txt")
solve("../testcases/16_10/02.txt")


# # ../testcases/16_10/01.txt
# 1935

# # ../testcases/16_10/02.txt
# 1964
