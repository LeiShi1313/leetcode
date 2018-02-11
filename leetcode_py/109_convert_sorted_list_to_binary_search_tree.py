# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def build_list(l):
    if not l:
        return None
    p = head = ListNode(l[0])
    for val in l[1:]:
        node = ListNode(val)
        p.next = node
        p = p.next
    return head

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def sortedListToBST(self, head):
        """
        :type head: ListNode
        :rtype: TreeNode
        """
        return self.build(head, None)
    
    def build(self, head, end):
        if head == end:
            return None
        slow = fast = head
        while fast != end and fast.next != end:
            slow = slow.next
            fast = fast.next.next
        mid = TreeNode(slow.val)
        mid.left = self.build(head, slow)
        mid.right = self.build(slow.next, end)
        return mid

if __name__ == '__main__':
    print(Solution().sortedListToBST(build_list([-10,-3,0,5,9])))