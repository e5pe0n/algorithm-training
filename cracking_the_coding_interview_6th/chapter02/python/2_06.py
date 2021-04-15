# https://www.geeksforgeeks.org/data-structures/linked-list/
class Node:
    def __init__(self):
        self.data: int = -1
        self.nxt: Node = None


class LinkedList:
    def __init__(self):
        self.head: Node = None

    def __repr__(self):
        node = self.head
        lst = []
        while node is not None:
            lst.append(node.data)
            node = node.nxt
        return repr(lst)

    def __len__(self):
        cnt = 0
        cur = self.head
        while cur is not None:
            cur = cur.nxt
            cnt += 1
        return cnt

    def push(self, new_data: int):
        new_node = Node()
        new_node.data = new_data
        new_node.nxt = self.head
        self.head = new_node

    def insert_after(self, prev_node: Node, new_data: int):
        assert prev_node is not None

        new_node = Node()
        new_node.data = new_data
        new_node.nxt = prev_node.nxt
        prev_node.nxt = new_node

    def append(self, new_data: int):
        new_node = Node()
        new_node.data = new_data
        new_node.nxt = None

        if self.head is None:
            self.head = new_node
            return

        last = self.head
        while last.nxt is not None:
            last = last.nxt
        last.nxt = new_node

    def delete_node(self, key):
        tmp = self.head
        prv = None

        if tmp is not None and tmp.data == key:
            self.head = tmp.nxt
            return

        while tmp is not None and tmp.data != key:
            prv = tmp
            tmp = tmp.nxt

        if tmp is None:
            return

        prv.nxt = tmp.nxt

    def delete_node_by_pos(self, pos):
        if self.head is None:
            return

        tmp = self.head

        if pos == 0:
            self.head = tmp.nxt
            return

        for _ in range(pos - 1):
            tmp = tmp.nxt
            if tmp is None:
                return

        if tmp.nxt is None:
            return

        tmp.nxt = tmp.nxt.nxt

    def delete_list(self):
        self.head = None

    def search(self, x):
        cur = self.head
        while cur is not None:
            if cur.data == x:
                return True
            cur = cur.nxt
        return False

    def get(self, pos):
        cur = self.head
        cnt = 0
        while cur is not None:
            if cnt == pos:
                return cur.data
            cnt += 1
            cur = cur.nxt
        raise IndexError("index out of range")


# # is_palindrome1
# [114 97 99 101 99 97 114] is palindrome
# [110 111 108 101 109 111 110 110 111 109 101 108 111 110] is palindrome
# [110 111 108 101 109 111 110 110 97 109 101 108 111 110] is not palindrome
# [110 111 108 101 109 111 110 110 97 109 101 108 111 111] is not palindrome
# [111 111 108 101 109 111 110 110 97 109 101 108 111 110] is not palindrome

# # is_palindrome2
# [114 97 99 101 99 97 114] is palindrome
# [110 111 108 101 109 111 110 110 111 109 101 108 111 110] is palindrome
# [110 111 108 101 109 111 110 110 97 109 101 108 111 110] is not palindrome
# [110 111 108 101 109 111 110 110 97 109 101 108 111 111] is not palindrome
# [111 111 108 101 109 111 110 110 97 109 101 108 111 110] is not palindrome

# # is_palindrome3
# [114 97 99 101 99 97 114] is palindrome
# [110 111 108 101 109 111 110 110 111 109 101 108 111 110] is palindrome
# [110 111 108 101 109 111 110 110 97 109 101 108 111 110] is not palindrome
# [110 111 108 101 109 111 110 110 97 109 101 108 111 111] is not palindrome
# [111 111 108 101 109 111 110 110 97 109 101 108 111 110] is not palindrome

# # is_palindrome4
# [114 97 99 101 99 97 114] is palindrome
# [110 111 108 101 109 111 110 110 111 109 101 108 111 110] is palindrome
# [110 111 108 101 109 111 110 110 97 109 101 108 111 110] is not palindrome
# [110 111 108 101 109 111 110 110 97 109 101 108 111 111] is not palindrome
# [111 111 108 101 109 111 110 110 97 109 101 108 111 110] is not palindrome

# # is_palindrome5
# [114 97 99 101 99 97 114] is palindrome
# [110 111 108 101 109 111 110 110 111 109 101 108 111 110] is palindrome
# [110 111 108 101 109 111 110 110 97 109 101 108 111 110] is not palindrome
# [110 111 108 101 109 111 110 110 97 109 101 108 111 111] is not palindrome
# [111 111 108 101 109 111 110 110 97 109 101 108 111 110] is not palindrome

# # is_palindrome6
# [114 97 99 101 99 97 114] is palindrome
# [110 111 108 101 109 111 110 110 111 109 101 108 111 110] is palindrome
# [110 111 108 101 109 111 110 110 97 109 101 108 111 110] is not palindrome
# [110 111 108 101 109 111 110 110 97 109 101 108 111 111] is not palindrome
# [111 111 108 101 109 111 110 110 97 109 101 108 111 110] is not palindrome

# # is_palindrome7
# [114 97 99 101 99 97 114] is palindrome
# [110 111 108 101 109 111 110 110 111 109 101 108 111 110] is palindrome
# [110 111 108 101 109 111 110 110 97 109 101 108 111 110] is not palindrome
# [110 111 108 101 109 111 110 110 97 109 101 108 111 111] is not palindrome
# [111 111 108 101 109 111 110 110 97 109 101 108 111 110] is not palindrome
