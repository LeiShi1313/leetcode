from binarytree import Tree, TreeNode

def test(node):
    print(node.val)

def dfs(node):
    if not node:
        return
    test(node)
    dfs(node.left)
    dfs(node.right)
    

if __name__ == '__main__':
    tree_list = [5, 3, 8, 1, 4, 6, 10, None, 2, None, None, None, None, 9]
    tree = Tree.from_list(tree_list)
    dfs(tree.root)