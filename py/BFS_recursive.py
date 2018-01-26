from binarytree import Tree, TreeNode
from queue import Queue as Q

def test(node):
    print(node.val)

def _bfs(queue):
    if not queue.empty():
        node = queue.get()
        test(node)
        if node.left:
            queue.put(node.left)
        if node.right:
            queue.put(node.right)
        _bfs(queue)

def bfs(root):
    queue = Q()
    if root:
        queue.put(root)
    _bfs(queue)
    

if __name__ == '__main__':
    tree_list = [5, 3, 8, 1, 4, 6, 10, None, 2, None, None, None, None, 9]
    tree = Tree.from_list(tree_list)
    bfs(tree.root)