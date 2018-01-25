import random
class RandomizedCollection(object):
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.map = {}
        self.vec = []

    def insert(self, val):
        """
        Inserts a value to the collection. Returns true if the collection did not already contain the specified element.
        :type val: int
        :rtype: bool
        """
        res = val in self.map
        idx = len(self.vec)
        if res:
            self.map[val].append(idx)
            self.vec.append(val)
        else:
            self.map[val] = [idx]
            self.vec.append(val)
        return not res

    def remove(self, val):
        """
        Removes a value from the collection. Returns true if the collection contained the specified element.
        :type val: int
        :rtype: bool
        """
        res = val in self.map
        if res:
            idx = self.map[val][-1]
            if idx != len(self.vec) - 1:
                num_back = self.vec[-1]
                self.map[num_back].remove(len(self.vec) - 1)
                self.vec[-1], self.vec[idx] = self.vec[idx], self.vec[-1]
                self.map[val].pop()
                if len(self.map[val]) == 0:
                    del self.map[val]
                self.vec.pop()
                self.map[num_back].append(idx)
            else:
                self.map[val].pop()
                if len(self.map[val]) == 0:
                    del self.map[val]
                self.vec.pop()
        return res

    def getRandom(self):
        """
        Get a random element from the collection.
        :rtype: int
        """
        return random.choice(self.vec)

if __name__ == '__main__':
    collection = RandomizedCollection()
    print collection.insert(0)
    print collection.insert(1)
    print collection.insert(2)
    print collection.insert(3)
    print collection.insert(3)
    print collection.remove(2)
    print collection.remove(3)
    print collection.remove(0)
    print collection.getRandom()
    print collection.getRandom()
    print collection.getRandom()
