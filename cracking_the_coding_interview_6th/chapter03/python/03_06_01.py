from collections import deque


class Animal:
    def __init__(self, idx) -> None:
        self.idx = idx

    def __repr__(self) -> str:
        return f"Animal: {self.idx}"


class Dog(Animal):
    def __init__(self, idx) -> None:
        super().__init__(idx)

    def __repr__(self) -> str:
        return f"Dog: {self.idx}"


class Cat(Animal):
    def __init__(self, idx) -> None:
        super().__init__(idx)

    def __repr__(self) -> str:
        return f"Cat: {self.idx}"


class EmptyQueueException(Exception):
    def __init__(self) -> None:
        super().__init__("queue is empty")


class AnimalShelter:
    class Data:
        def __init__(self, order: int, obj: Animal) -> None:
            self.order = order
            self.obj = obj

    def __init__(self) -> None:
        self.cnt = 0
        self.dog_q = deque()
        self.cat_q = deque()

    def __len__(self) -> int:
        return len(self.dog_q) + len(self.cat_q)

    def is_empty(self) -> bool:
        return len(self) == 0

    def enqueue(self, x: Animal) -> None:
        if isinstance(x, Dog):
            self.dog_q.append(self.Data(self.cnt, x))
            self.cnt += 1
        if isinstance(x, Cat):
            self.cat_q.append(self.Data(self.cnt, x))
            self.cnt += 1

    def dequeue_any(self) -> Animal:
        if self.is_empty():
            raise EmptyQueueException()
        if len(self.cat_q) == 0:
            return self.dog_q.popleft().obj
        if len(self.dog_q) == 0:
            return self.cat_q.popleft().obj
        if self.cat_q[0].order > self.dog_q[0].order:
            return self.dog_q.popleft().obj
        else:
            return self.cat_q.popleft().obj

    def dequeue_dog(self) -> Dog:
        if len(self.dog_q) == 0:
            raise EmptyQueueException()
        return self.dog_q.popleft().obj

    def dequeue_cat(self) -> Cat:
        if len(self.cat_q) == 0:
            raise EmptyQueueException()
        return self.cat_q.popleft().obj


v = [Dog(1), Cat(2), Dog(3), Dog(4), Dog(5), Cat(6), Cat(7),
     Cat(8), Dog(9), Cat(10), Dog(11), Cat(12), Dog(13)]
s = AnimalShelter()
for x in v:
    s.enqueue(x)

print(s.dequeue_any())
print(s.dequeue_any())
print(s.dequeue_any())
print()

print(s.dequeue_cat())
print(s.dequeue_cat())
print(s.dequeue_cat())
print()

print(s.dequeue_dog())
print(s.dequeue_dog())
print()

print(s.dequeue_cat())
print(s.dequeue_dog())
print(s.dequeue_cat())
print()

while not s.is_empty():
    print(s.dequeue_any())

# Dog: 1
# Cat: 2
# Dog: 3

# Cat: 6
# Cat: 7
# Cat: 8

# Dog: 4
# Dog: 5

# Cat: 10
# Dog: 9
# Cat: 12

# Dog: 11
# Dog: 13
