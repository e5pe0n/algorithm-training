class Node:
    def __init__(
            self,
            key: int,
            p=None,     # Node
            left=None,  # Node
            right=None  # Node
    ):
        self.key = key
        self.p = p
        self.left = left
        self.right = right

    def __str__(self):
        l_key = self.left.key if self.left else None
        r_key = self.right.key if self.right else None
        return 'key: %d, l_key: %d, r_key: %d' % (self.key, l_key, r_key)


class Tree:
    def __init__(self, x: Node):
        self.root = x


def inorder_tree_walk(x: Node):
    if x is not None:
        inorder_tree_walk(x.left)
        print("%d, " % x.key, end='')
        inorder_tree_walk(x.right)


def tree_search(x: Node, k: int):
    while x is not None and k != x.key:
        if k < x.key:
            x = x.left
        else:
            x = x.right
    return x


def tree_maximum(x: Node):
    while x.right is not None:
        x = x.right
    return x


def tree_minimum(x: Node):
    while x.left is not None:
        x = x.left
    return x


def tree_successor(x: Node):
    if (x.right is not None):
        return tree_minimum(x.right)
    y = x.p
    while y is not None and x is y.right:
        x = y
        y = x.p
    return y


def tree_insert(T: Tree, z: Node):
    y = None
    x = T.root
    while x is not None:
        y = x
        if z.key < x.key:
            x = x.left
        else:
            x = x.right
    z.p = y
    if y is None:
        T.root = z
    elif z.key < y.key:
        y.left = z
    else:
        y.right = z


def transplant(T: Tree, u: Node, v: Node):
    if u.p is None:
        Tree.root = v
    elif u.p.right is u:
        u.p.right = v
    elif u.p.left is u:
        u.p.left = v
    if v is not None:
        v.p = u.p


def tree_delete(T: Tree, z: Node):
    if z.left is None:
        transplant(T, z, z.right)
    elif z.right is None:
        transplant(T, z, z.left)
    else:
        y = tree_minimum(z.right)
        if y.p is not z:
            transplant(T, y, y.right)
            y.right = z.right
            y.right.p = y
        transplant(T, z, y)
        y.left = z.left
        y.left.p = y


def main():
    n12 = Node(12)
    n5 = Node(5, n12)
    n2 = Node(2, n5)
    n9 = Node(9, n5)
    n10 = Node(10, n9)
    n18 = Node(18, n12)
    n15 = Node(15, n18)
    n17 = Node(17, n15)
    n19 = Node(19, n18)

    n12.left = n5
    n12.right = n18
    n5.left = n2
    n5.right = n9
    n9.right = n10
    n18.left = n15
    n18.right = n19
    n15.right = n17

    T = Tree(n12)

    print('inorder_tree_walk: ', end='')
    inorder_tree_walk(T.root)
    print('')

    print('tree_search(T.root, 5): %s' % tree_search(T.root, 5))
    print('tree_search(T.root, 3): %s' % tree_search(T.root, 3))

    print('tree_successor(n10): %s' % tree_successor(n10))
    print('tree_successor(n19): %s' % tree_successor(n19))

    n13 = Node(13)
    print('tree_insert(T, n13)')
    tree_insert(T, n13)

    print('inorder_tree_walk: ', end='')
    inorder_tree_walk(T.root)
    print('')

    print('tree_delete(T, n15)')
    tree_delete(T, n15)

    print('inorder_tree_walk: ', end='')
    inorder_tree_walk(T.root)
    print('')


if __name__ == '__main__':
    main()
