import math

class Solution(object):
    def getFactors(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        res = []
        if n <= 1:
            return [[]]
        res = []
        for i in range(2, int(math.sqrt(n))+1):
            if n % i == 0:
                [res.append([i] + rest) for rest in self._getFactors(i, n / i)]
        return res

    def _getFactors(self, m, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """

        if n <= 1:
            return [[]]
        res = []
        for i in range(m, int(math.sqrt(n))+1):
            if n % i == 0:
                [res.append([i] + rest) for rest in self._getFactors(i, n / i)]
        res.append([n])
        return res

if __name__ == '__main__':
    print Solution().getFactors(12)
