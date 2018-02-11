from queue import Queue as Q

class TreeNode(object):
    def __init__(self, val):
        self.val = val
        self.child = []

    def __repr__(self):
        return str(self.val)


class Tree(object):
    def __init__(self, root):
        self.root = root

    def inorder(self):
        ret = ''
        s = []
        p = self.root
        go_left = True
        while p:
            if p.left and go_left:
                s.append(p)
                p = p.left
                go_left = True
            else:
                ret += str(p) + ', '
                if p.right:
                    p = p.right
                    go_left = True
                elif s:
                    go_left = False
                    p = s.pop()
                else:
                    p = None
        return ret[:-2]

    @classmethod
    def from_list(cls, l):
        if not l:
            return cls(None)
        root = TreeNode(l[0])
        q = Q()
        q.put(root)
        is_left = True
        for val in l[1:]:
            node = TreeNode(val) if val else None
            n = q.queue[0]
            if is_left:
                n.left = node
            else:
                n.right = node
                q.get()
            is_left = not is_left
            q.put(node)
        return cls(root)


if __name__ == '__main__':
    l = [3, 1, 7, 3, 2, 5, 8, None, None, None, 4, 6]
    tree = Tree.from_list(l)
    print(tree.inorder())

    l = [5, 3, 8, 1, 4, 6, 10, None, 2, None, None, None, None, 9]
    tree = Tree.from_list(l)
    print(tree.inorder())
