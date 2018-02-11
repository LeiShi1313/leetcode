from binarytree import TreeNode, Tree
from utils import check

def find_LCA(root, a, b):
    if not root:
        return None

    if a > b:
        a, b = b, a

    p = root
    while p:
        if a < p.val and b < p.val:
            p = p.left
        elif a > p.val and b > p.val:
            p = p.right
        else:
            return p.val
    return None

if __name__ == '__main__':
    l = [5, 3, 8, 1, 4, 6, 10, None, 2, None, None, None, None, 9]
    tree = Tree.from_list(l)

    check(find_LCA(tree.root, 1, 2), 1)
    check(find_LCA(tree.root, 4, 8), 5)
    check(find_LCA(tree.root, 1, 4), 3)
    check(find_LCA(tree.root, 6, 9), 8)