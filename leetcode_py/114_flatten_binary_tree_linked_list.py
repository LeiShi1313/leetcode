import os
import sys
dir_name = os.path.realpath(".")
sys.path.append(dir_name)
from py.utils import check
from py.binarytree import Tree

class Solution:
    def flatten(self, root):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        """
        p = root
        while p:
            if p.left and p.right:
                _p = p.left
                while _p.right:
                    _p = _p.right
                _p.right = p.right
            if p.left:
                p.right = p.left
                p.left = None
            p = p.right


if __name__ == '__main__':
    print(Solution().flatten(None))
    print(Solution().flatten(Tree.from_list([1,2]).root))
    print(Solution().flatten(Tree.from_list([1,2,5,3,4,None,6]).root))