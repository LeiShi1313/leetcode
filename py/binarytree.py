from queue import Queue as Q

class TreeNode(object):
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

    def __repr__(self):
        return str(self.val)

    def __eq__(self, other):
        return self.val == other.val if isinstance(other, TreeNode) else False

    def __lt__(self, other):
        return self.val < other.val


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
            if node:
                q.put(node)
        return cls(root)


if __name__ == '__main__':
    l = [3, 1, 7, 3, 2, 5, 8, None, None, None, 4, 6]
    tree = Tree.from_list(l)
    print(tree.inorder())

    l = [5, 3, 8, 1, 4, 6, 10, None, 2, None, None, None, None, 9]
    tree = Tree.from_list(l)
    print(tree.inorder())

    l = [37,-34,-48,None,-100,-100,48,None,None,None,None,-54,None,-71,-22,None,None,None,8]
    tree = Tree.from_list(l)
    print(tree.inorder())
