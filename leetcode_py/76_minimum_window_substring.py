from collections import defaultdict
class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        begin, end = 0, 0
        t_set = defaultdict(int)
        for c in t:
            t_set[c] += 1
        m = len(s) + 1
        head, counter = 0, len(t)
        while end < len(s):
            if (t_set[s[end]] > 0):
                counter -= 1
            t_set[s[end]] -= 1
            end += 1
            while counter == 0:
                if end - begin < m:
                    head = begin
                    m = end - begin
                if t_set[s[begin]] == 0:
                    counter += 1
                t_set[s[begin]] += 1
                begin += 1
        return "" if m == len(s) + 1 else s[head:head+m]


if __name__ == '__main__':
    print(Solution().minWindow("ADOBECODEBANC", "ABC"))
    print(Solution().minWindow("aa", "aa"))