class A:
    def __init__(self):
        self.v = 0
        self.__v = 1


class B(A):
    pass


b = B()
print(b.v)
print(b.__v)
