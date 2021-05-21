from __future__ import annotations
from enum import Enum


class Rank(Enum):
    responder = 0
    manager = 1
    director = 2


class Caller:
    pass


class Employee:
    def __init__(self, handler: CallHandler):
        self.__current_call = None
        self._rank

    def recieve_call(self, call: Call):
        pass

    def call_completed(self):
        pass

    def escalate_and_reassign(self):
        pass

    def assign_new_call(self):
        pass

    def is_free(self) -> bool:
        return self.__current_call is not None

    @property
    def rank(self) -> Rank:
        return self._rank


class Director(Employee):
    def __init__(self, handler):
        super().__init__(handler)
        self._rank = Rank.director


class Manager(Employee):
    def __init__(self, handler):
        super().__init__(handler)
        self._rank = Rank.manager


class Responder(Employee):
    def __init__(self, handler):
        super().__init__(handler)
        self._rank = Rank.responder


class Call:
    def __init__(self):
        self.rank = Rank.responder
        self.__caller = None
        self.handler = None

    def reply(self, message: str):
        pass

    def incrementRank() -> Rank:
        pass

    def disconnect() -> None:
        pass


class CallHandler:
    __LEVELS = 3

    __NUM_RESPONDENTS = 10
    __NUM_MANAGERS = 4
    __NUM_DIRECTORS = 3

    def get_handler_for_call(self, call: Call) -> Employee:
        pass

    def dispatch_call_with_caller(self, caller: Caller) -> None:
        call = Call(caller)
        self.dispatch_call(call)

    def dispatch_call(self, call: Call) -> None:
        emp = self.get_handler_for_call(call)
        if emp:
            emp.recieve_call(call)
            call.handler = emp
        else:
            call.reply("Please wait for free employee to reply")
            self.call_queue[call.rank.value].append(call)
