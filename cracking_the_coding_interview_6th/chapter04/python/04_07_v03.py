from typing import Dict, List, ValuesView


class Project:
    def __init__(self, name: int):
        self.__name: str = name
        self.__dependencies: int = 0
        self.__children = {}  # Dict[int, Project]

    def add_neighbor(
        self,
        node    # Project
    ):
        if node.name not in self.__children:
            self.__children[node.name] = node
            node.increment_dependencies()

    @property
    def name(self) -> int:
        return self.__name

    @property
    def children(self):  # -> ValuesView[Project]
        return self.__children.values()

    @property
    def dependencies(self) -> int:
        return self.__dependencies

    def increment_dependencies(self) -> None:
        self.__dependencies += 1

    def decrement_dependencies(self) -> None:
        self.__dependencies -= 1


class Graph:
    def __init__(self):
        self.__nodes: Dict[int, Project] = {}

    @property
    def nodes(self) -> ValuesView[Project]:
        return self.__nodes.values()

    def get_or_create_node(self, name: int) -> Project:
        if name not in self.__nodes:
            self.__nodes[name] = Project(name)
        return self.__nodes[name]

    def add_edge(self, start_name, end_name) -> None:
        start, end = map(self.get_or_create_node, (start_name, end_name))
        start.add_neighbor(end)


def add_non_dependent(order: List[Project], projects: List[Project], offset: int) -> int:
    for project in projects:
        if project.dependencies == 0:
            order[offset] = project
            offset += 1
    return offset


def order_project(projects: List[Project]) -> List[Project]:
    order: List[Project] = [None] * len(projects)
    end_of_list = add_non_dependent(order, projects, 0)
    to_be_processed = 0
    while to_be_processed < len(order):
        current = order[to_be_processed]
        if current is None:
            return []
        for child in current.children:
            child.decrement_dependencies()
        end_of_list = add_non_dependent(order, current.children, end_of_list)
        to_be_processed += 1
    return order


def ns(f):
    return next(f).strip()


def solve(fp: str) -> None:
    print(f"# {fp}")
    with open(fp) as f:
        n, m = map(int, ns(f).split())
        graph = Graph()
        for i in range(n):
            graph.get_or_create_node(i)
        for _ in range(m):
            u, v = map(lambda x: int(x) - 1, ns(f).split())
            graph.add_edge(u, v)
    res = order_project(graph.nodes)
    print(" ".join(list(map(lambda x: str(x.name + 1), res))) if res else "error")
    print()


solve("../testcases/04_07/01.txt")
solve("../testcases/04_07/02.txt")
solve("../testcases/04_07/03.txt")
solve("../testcases/04_07/04.txt")
solve("../testcases/04_07/05.txt")
solve("../testcases/04_07/06.txt")

# # ../testcases/04_07/01.txt
# 5 6 2 1 4 3

# # ../testcases/04_07/02.txt
# error

# # ../testcases/04_07/03.txt
# 2 3 8 1 5 12 9 4 7 6 10 11

# # ../testcases/04_07/04.txt
# error

# # ../testcases/04_07/05.txt
# 1 2

# # ../testcases/04_07/06.txt
# error
