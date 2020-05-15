import math


class vEBTree:
    def __init__(self, u: int):
        self.u = u
        self.min_val = -1
        self.max_val = -1
        self.sqrt_u_upper = math.ceil(math.sqrt(u))
        self.sqrt_u_lower = int(math.sqrt(u))
        self.summary = None
        self.cluster = None

        if self.u >= 2:
            self.summary = vEBTree(self.sqrt_u_upper)
            self.cluster = [vEBTree(self.sqrt_u_lower) for _ in range(self.sqrt_u_upper)]

    def high(self, x: int):
        return x / self.sqrt_u_lower

    def low(self, x: int):
        return x % self.sqrt_u_lower

    def index(self, x: int, y: int):
        return x * self.sqrt_u_lower + y

    def vEB_tree_minimum(self):
        return self.min_val

    def vEB_tree_maximum(self):
        return self.max_val

    def vEB_tree_member(self, x: int) -> bool:
        if x == self.min_val or x == self.max_val:
            return True
        elif self.u == 2:
            return False
        else:
            return self.cluster[self.high(x)].vEB_tree_member(self.low(x))

    def vEB_tree_successor(self, x: int) -> int:
        if self.u == 2:
            if x == 0 and self.max_val == 1:
                return 1
            else:
                return -1
        elif self.min_val != -1 and x < self.min_val:
            return self.min_val
        else:
            max_low = self.cluster[self.high(x)].vEB_tree_maximum()
            if max_low != -1 and self.low(x) < max_low:
                offset = self.cluster[self.high(x)].vEB_tree_successor(self.low(x))
                return self.index(self.high(x), offset)
            else:
                succ_cluster = self.summary.vEB_tree_successor(self.high(x))
                if succ_cluster == -1:
                    return -1
                else:
                    offset = self.cluster[succ_cluster].vEB_tree_minimum()
                    return self.index(succ_cluster, offset)

    def vEB_tree_predecessor(self, x: int) -> int:
        if self.u == 2:
            if x == 1 and self.min_val == 0:
                return 0
            else:
                return -1
        elif self.max_val != -1 and x > self.max_val:
            return self.max_val
        else:
            min_low = self.cluster[self.high(x)].vEB_tree_minimum()
            if min_low != -1 and x > min_low:
                offset = self.cluster[self.high(x)].vEB_tree_predecessor(self.low(x))
                return self.index(self.high(x), offset)
            else:
                pred_cluster = self.summary.vEB_tree_predecessor(self.high(x))
                if (pred_cluster == -1):
                    if self.min_val != -1 and self.min_val < x:
                        return self.min_val
                    else:
                        return -1
                else:
                    offset = self.cluster[pred_cluster].vEB_tree_maximum()
                    return self.index(pred_cluster, offset)

    def vEB_empty_tree_insert(self, x: int):
        self.min = x
        self.max = x

    def vEB_tree_insert(self, x: int):
        if self.min_val == -1:
            self.vEB_empty_tree_insert(x)
        else:
            if x < self.min_val:
                x, self.min_val = self.min_val, x
            if self.u > 2:
                if self.cluster[self.high(x)].vEB_tree_minimum() == -1:
                    self.summary.vEB_tree_insert(self.high(x))
                    self.cluster[self.high(x)].vEB_empty_tree_insert(self.low(x))
                else:
                    self.cluster[self.high(x)].vEB_tree_insert(self.low(x))
            if x > self.max_val:
                self.max_val = x

    def vEB_tree_delete(self, x: int):
        if self.min_val == self.max_val:
            self.min_val = -1
            self.max_val = -1
        elif self.u == 2:
            if x == 0:
                self.min_val = 1
            else:
                self.min_val = 0
        else:
            if x == self.min_val:
                first_cluster = self.summary.vEB_tree_minimum()
                x = self.index(first_cluster, self.cluster[first_cluster].vEB_tree_minimum())
                self.min_val = x
            self.cluster[self.high(x)].vEB_tree_delete(self.low(x))
            if self.clsuter[self.high(x)].vEB_tree_minimum() == -1:
                self.summary.vEB_tree_delete(self.high(x))
                if x == self.max_val:
                    summary_max = self.summary.vEB_tree_maximum()
                    if summary_max == -1:
                        self.max_val = self.min_val
                    else:
                        self.max_val = self.index(summary_max, self.cluster[summary_max].vEB_tree_maximum())
            elif x == self.max_val:
                self.max_val = self.index(self.high(x), self.cluster[self.high(x)].vEB_tree_maximum())
