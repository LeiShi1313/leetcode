class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        wordSet = set(wordDict)
        mem = [False] * (len(s)+1)
        mem[0] = True
        for i in range(len(s)):
            for j in range(i, -1, -1):
                if s[j:i+1] in wordSet and mem[j]:
                    mem[i+1] = True
        return mem[len(s)]

        



if __name__ == '__main__':
    print(Solution().wordBreak("leetcode", ["leet", "code"]))
    print(Solution().wordBreak("s", ["s"]))