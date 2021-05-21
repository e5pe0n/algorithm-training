from typing import Type


class Task:
    def __init__(self, task_id):
        self.__task_id = task_id

    @property
    def task_id(self) -> int:
        return self.__task_id


class Employee:
    def can_handle() -> bool:
        pass


class Respondent(Employee):
    pass


class Manager(Employee):
    pass


class Director(Employee):
    pass


class AssignmentTable:
    def __init__(self):
        self.__frees = []
        self.__assigneds = {}

    def push_free(self, employee) -> None:
        self.__frees.append(employee)

    def frees_size(self) -> int:
        return len(self.__frees)

    def pop_free(self) -> Employee:
        return self.__frees.pop()

    def assign(self, e: Employee, task: Task) -> None:
        self.__assigneds[task] = e


class CallCenter:
    def __init__(self):
        self.__respondents = AssignmentTable()
        self.__managers = AssignmentTable()
        self.__directors = AssignmentTable()
        self.__task_id = 0

    def __control_assign(self, e: Employee, task: Task) -> None:
        if isinstance(e, Respondent):
            self.__respondents.assign(e, task)
        elif isinstance(e, Manager):
            self.__managers.assign(e, task)
        elif isinstance(e, Director):
            self.__directors.assign(e, task)

    def __assign(self, e: Employee, task: Task) -> bool:
        if e.can_handle():
            self.__control_assign(e, task)
            return True
        return False

    def __escalate(self, to: Type[Employee], task: Task) -> bool:
        if to == Manager:
            if self.__managers.frees_size() == 0:
                return self.__escalate(Director, task)
            if self.__assign(self.__managers.pop_free(), task):
                return True
            return self.__escalate(Director, task)
        elif to == Director:
            if self.__directors.frees_size == 0:
                return False
            return self.__assign(self.__directors.pop_free(), task)
        else:
            return False

    def dispatch_call(self) -> bool:
        task = Task(self.__task_id)
        self.__task_id += 1

        if self.__respondents.frees_size() == 0:
            return self.__escalate(Manager, task)
        if self.__assign(self.__respondents.pop_free(), task):
            return True
        return self.__escalate(Manager, task)
