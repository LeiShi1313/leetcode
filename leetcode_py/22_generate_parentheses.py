class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        res = [[""]]

        for i in range(1, n + 1):
            res.append([])
            for j in range(i):
                for p in res[j]:
                    for pp in res[i - j - 1]:
                        res[i].append('(' + p + ')' + pp)
        return res[n]

if __name__ == '__main__':
    print Solution().generateParenthesis(3)
