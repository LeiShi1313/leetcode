from collections import defaultdict
class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: List[str]
        """
        l = len(s)
        mem = [False] * (l + 1)
        mem[0] = True
        wordSet = set(wordDict)
        
        for i in range(1, l+1):
            for j in range(i):
                if mem[j] and s[j:i] in wordSet:
                    mem[i] = True
                    break
        if not mem[l]:
            return []
        
        d = defaultdict(list)
        d[0] = [""]
        for i in range(l+1):
            for j in range(i):
                if d[j] and s[j:i] in wordSet:
                    for v in d[j]:
                        d[i].append(v + " " + s[j:i] if v else s[j:i])
        return d[l]
        
            


if __name__ == '__main__':
    print(Solution().wordBreak("leetcode", ["leet", "code"]))
    print(Solution().wordBreak("s", ["s"]))
    print(Solution().wordBreak("catsanddog", ["cat", "cats", "and", "sand", "dog"]))