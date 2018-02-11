from binarytree import TreeNode, Tree

def find_path(node, path, val):
    if not node:
        return False
    path.append(node.val)
    if node.val == val:
        return True

    if (node.left and find_path(node.left, path, val)) or \
        (node.right and find_path(node.right, path, val)):
        return True
    path.pop()
    return False

def find_LCA(root, a, b):
    if not root:
        return None

    path1 = []
    path2 = []

    if not find_path(root, path1, a) or not find_path(root, path2, b):
        return None

    i = 0
    while i < len(path1) and i < len(path2):
        if path1[i] != path2[i]:
            break
        i += 1
    return path1[i-1]

if __name__ == '__main__':
    l = [5, 3, 8, 1, 4, 6, 10, None, 2, None, None, None, None, 9]
    tree = Tree.from_list(l)
    assert find_LCA(tree.root, 1, 2) == 1
    assert find_LCA(tree.root, 4, 8) == 5
    assert find_LCA(tree.root, 1, 4) == 3
    assert find_LCA(tree.root, 6, 9) == 8