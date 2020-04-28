from enum import Enum


class Color(Enum):
    BLACK = 0
    RED = 1


class Node:
    def __init__(
        self,
        key: int,
        color: Color,
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
        return 'key: %s, color: %s, left: %s, right: %s' % (self.key, self.color.name, l_key, r_key)


class Tree:
    def __init__(
        self,
        root    # Node
    ):
        self.root = root
        self.nil = None

        self.root.p = self.nil

    def tree_minimum(self, x: Node):
        while x.left is not self.nil:
            x = x.left
        return x

    def _rb_transplant(self, u: Node, v: Node):
        if u is self.root:
            self.root = v
        elif u.p.left is u:
            u.p.left = v
        else:
            u.p.right = v
        v.p = u.p

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

    def _rb_insert_fixup(self, z: Node):
        while z.p.color is Color.RED:
            if z.p is z.p.p.left:
                y = z.p.p.left
                if y.color is Color.RED:
                    z.p.color = Color.BLACK
                    y.color = Color.BLACK
                    z.p.p.color = Color.RED
                    z = z.p.p
                else:
                    if z is z.p.right:
                        z = z.p
                        self.left_rotate(z)
                    z.p.color = Color.BLACK
                    z.p.p.color = Color.RED
                    self.right_rotate(z)
            else:
                y = z.p.p.right
                if y.color is Color.RED:
                    z.p.color = Color.BLACK
                    y.color = Color.BLACK
                    z.p.p.color = Color.RED
                    z = z.p.p
                else:
                    if z is z.p.left:
                        z = z.p
                        self.right_rotate(z)
                    z.p.color = Color.BLACK
                    z.p.p.color = Color.RED
                    self.left_rotate(z.p.p)
            self.root.color = Color.BLACK

    def rb_insert(self, z: Node):
        y = self.nil
        x = self.root
        while x is not self.nil:
            y = x
            if z.key < x.key:
                x = x.left
            else:
                x = x.right
        z.p = y
        if y is self.nil:
            self.root = z
        elif z.key < y.key:
            y.left = z
        else:
            y.right = z
        z.left = self.nil
        z.right = self.nil
        z.color = Color.RED
        self._rb_insert_fixup(z)

    def _rb_delete_fixup(self, x: Node):
        while x is not self.root and x.color is Color.BLACK:
            if x is x.p.left:
                w = x.p.right
                if w.color is Color.RED:
                    w.color = Color.BLACK
                    x.p.color = Color.RED
                    self.left_rotate(x.p)
                    w = x.p.right
                if w.left.color is Color.BLACK and w.right.color is Color.BLACK:
                    w.color = Color.RED
                    x = x.p
                else:
                    if w.right.color is Color.BLACK:
                        w.left.color = Color.BLACK
                        w.color = Color.RED
                        self.right_rotate(w)
                        w = x.p.right
                    w.color = x.p.color
                    x.p.color = Color.BLACK
                    x.right.color = Color.BLACK
                    self.left_rotate(x.p)
                    x = self.root
            else:
                w = x.p.left
                if w.color is Color.RED:
                    w.color = Color.BLACK
                    x.p.color = Color.RED
                    self.right_rotate(x.p)
                    w = w.p.left
                if w.left.color is Color.BLACK and w.right.color is Color.BLACK:
                    w.color = Color.RED
                    x = x.p
                else:
                    if w.left.color is Color.BLACK:
                        w.right.color = Color.BLACK
                        w.color = Color.RED
                        self.left_rotate(w)
                        w = x.p.left
                    w.color = x.p.color
                    x.p.color = Color.BLACK
                    x.left.color = Color.BLACK
                    self.right_rotate(x.p)
                    x = self.root
        x.color = Color.BLACK

    def rb_delete(self, z: Node):
        y = z
        y_original_color = y.color
        if z.left is self.nil:
            x = z.right
            self._rb_transplant(z, z.right)
        elif z.right is self.nil:
            x = z.left
            self._rb_transplant(z, z.left)
        else:
            y = self.tree_minimum(z.right)
            y_original_color = y.color
            x = y.right
            if y.p == z:
                x.p = y
            else:
                self._rb_transplant(y, y.right)
                y.right = z.right
                y.right.p = y
            self._rb_transplant(z, y)
            y.left = z.left
            y.left.p = y
            y.color = z.color
        if y_original_color is Color.BLACK:
            self._rb_delete_fixup(x)
