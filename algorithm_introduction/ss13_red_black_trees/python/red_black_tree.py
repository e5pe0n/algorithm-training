class Node:
    def __init__(
        self,
        key: int,
        color: int,  # black: 0, red: 1
        left=None,   # Node
        right=None,  # Node
        p=None,      # Node
    ):
        self.key = key
        self.color = color
        self.left = left
        self.right = right
        self.p = p

    def __str__(self):
        l_key = self.left.key if self.left else None
        r_key = self.right.key if self.right else None
        return 'key: %s, color: %s, left: %s, right: %s' % (self.key, self.color, l_key, r_key)


class Tree:
    def __init__(
        self,
        root    # Node
    ):
        self.root = root
        self.nil = None

    def left_rotate(self, x: Node):
        y = x.right

        x.right = y.left
        if y.left != self.nil:
            y.left.p = x
        y.p = x.p

        if x.p == self.nil:
            self.root = y
        elif x.p.left == x:
            x.p.left = y
        else:
            x.p.right = y

        y.left = x
        x.p = y

    def right_rotate(self, x: Node):
        y = x.left

        x.left = y.right
        if y.right != self.nil:
            y.right.p = x
        y.p = x.p

        if x.p == self.nil:
            self.root = y
        elif x.p.left == x:
            x.p.left = y
        else:
            x.p.right = y

        y.right = x
        x.p = y
