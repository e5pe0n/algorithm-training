class Node:
    def __init__(self, key, left=None, right=None):
        self.key = key
        self.left = left
        self.right = right

    def __str__(self):
        l_key = self.left.key if self.left else None
        r_key = self.right.key if self.right else None
        return f'key: {self.key}, left: {l_key}, right: {r_key}'


def f1(x):
    x = x.right
    print(x)


def main():
    n2 = Node(2)
    n3 = Node(3)
    n1 = Node(1, n2, n3)
    print(n1)
    f1(n1)
    print(n1)


if __name__ == '__main__':
    main()
