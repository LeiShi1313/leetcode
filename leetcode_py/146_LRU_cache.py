class ListNode(object):
    def __init__(self, key, val, next=None, pre=None):
        self.key = key
        self.val = val
        self.next = next
        self.pre = pre


class LinkedList(object):
    def __init__(self):
        self.dummy_head = ListNode(0, 0)
        self.back = self.dummy_head
        self.len = 0

    def move_to_head(self, node):
        if node.pre == self.dummy_head:
            return
        if node == self.back:
            self.back = node.pre
            self.back.next = None
        old_head = self.dummy_head.next
        self.dummy_head.next = node
        node.pre.next = node.next
        if node.next:
            node.next.pre = node.pre
        node.next = old_head
        node.pre = self.dummy_head
        old_head.pre = node

    def push(self, node):
        self.back.next = node
        node.pre = self.back
        self.back = node
        self.len += 1

    def pop_back(self):
        new_back = self.back.pre
        self.back = new_back
        self.back.next = None
        self.len -= 1

    @property
    def head(self):
        return self.dummy_head.next


class LRUCache(object):
    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.list = LinkedList()
        self.map = {}
        self.capacity = capacity

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        ret = self.map.get(key, -1)
        if ret != -1:
            self.list.move_to_head(self.map[key])
            self.map[key] = self.list.head
            ret = self.list.head.val
        return ret

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: void
        """
        if key in self.map:
            self.list.move_to_head(self.map[key])
            self.map[key] = self.list.head
            self.list.head.val = value
        else:
            if self.list.len >= self.capacity:
                node_to_remove = self.list.back
                self.list.pop_back()
                del self.map[node_to_remove.key]
            node = ListNode(key, value)
            self.list.push(node)
            self.list.move_to_head(node)
            self.map[key] = self.list.head

if __name__ == '__main__':
    cache = LRUCache(2)
    print cache.put(1,1),
    print cache.put(2,2),
    print cache.get(1),
    print cache.put(3,3),
    print cache.get(2),
    print cache.put(4,4),
    print cache.get(1),
    print cache.get(3),
    print cache.get(4)

    cache = LRUCache(3)
    print cache.put(1,1),
    print cache.put(2,2),
    print cache.put(3,3),
    print cache.put(4,4),
    print cache.get(4),
    print cache.get(3),
    print cache.get(2),
    print cache.get(1),
    print cache.put(5,5),
    print cache.get(1),
    print cache.get(2),
    print cache.get(3),
    print cache.get(4),
    print cache.get(5)
