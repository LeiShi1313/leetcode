# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
    def setLeft(self,val):
        self.left = val
    def setRight(self,val):
        self.right = val
    def getVal(self):
        return self.val
    def addVal(self,node):
        if self.val > node.getVal():
            if self.left:
                self.left.addVal(node)
            else:
                self.left = node
        else:
            if self.right:
                self.right.addVal(node)
            else:
                self.right = node

class Solution(object):
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        res = []
        self.iterator(range(1,n+1),None,res)
        return res

    def iterator(self,toPop,done,res):
        if len(toPop) == 0:
            res.append(done)
        else:
            for i in toPop:
                node = TreeNode(i)
                l = [k for k in toPop if k!= i]
                if done == None:
                    self.iterator(l,node,res)
                else:
                    node.addVal(node)
                    self.iterator(l,done,res)

        
