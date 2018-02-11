from binarytree import TreeNode, Tree
from utils import check

def find(node, a, b, level):
    if node == None:
        return (None, -1)

    if node.val == a or node.val == b:
        return (node.val, level)

    left = find(node.left, a, b, level+1)
    right = find(node.right, a, b, level+1)

    if left[0] and right[0]:
        if left[0] == a and right[0] == b:
            return (node.val, level)
        elif left[0] == b and right[0] == a:
            return (node.val, level)
        elif left[0] not in (a, b):
            if right[0] not in (a, b):
                return (left[0], level) if left[1] > right[1] else (right[0], level)
            else:
                return (left[0], level)
        elif right[0] not in (a, b):
            return (right[0], level)
        else:
            print("Too many situations to check")
            print("What happened")
    else:
        return (left[0], level) if left[0] else (right[0],level)

def find_LCA(root, a, b):
    return find(root, a, b, 0)[0]
    
    

if __name__ == '__main__':
    l = [5, 3, 8, 1, 4, 6, 10, None, 2, None, None, None, None, 9]
    tree = Tree.from_list(l)
    check(find_LCA(tree.root, 1, 2), 1)
    check(find_LCA(tree.root, 4, 8), 5)
    check(find_LCA(tree.root, 1, 4), 3)
    check(find_LCA(tree.root, 6, 9), 8)

    l = [37,-34,-48,None,-100,-100,48,None,None,None,None,-54,None,-71,-22,None,None,None,8]
    tree = Tree.from_list(l)
    check(find_LCA(tree.root, -100, 8), -48)

    l = [37,-34,-48,None,-100,-100,48,8,None,None,None,-54,None,-71,-22,None,None,None,8]
    tree = Tree.from_list(l)
    check(find_LCA(tree.root, -100, 8), -100)