from binarytree import TreeNode, Tree
from utils import check

def find_LCA(root, a, b):
    if not root:
        return None

    if root.val == a or root.val == b:
        return root.val

    left = find_LCA(root.left, a, b)
    right = find_LCA(root.right, a, b)

    if left and right:
        return root.val

    return left if left is not None else right

if __name__ == '__main__':
    l = [5, 3, 8, 1, 4, 6, 10, None, 2, None, None, None, None, 9]
    tree = Tree.from_list(l)

    print("This solution assume all the val exist in the tree")
    check(find_LCA(tree.root, 1, 2), 1)
    check(find_LCA(tree.root, 4, 8), 5)
    check(find_LCA(tree.root, 1, 4), 3)
    check(find_LCA(tree.root, 6, 9), 8)