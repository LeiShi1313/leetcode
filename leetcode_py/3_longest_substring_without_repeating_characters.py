from collections import defaultdict

class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        begin, end = 0, 0
        head, m = 0, 1
        s_set = defaultdict(int)
        counter = 0

        while end < len(s):
            if s_set[s[end]] > 0:
                counter += 1
            s_set[s[end]] += 1
            end += 1
            while counter > 0:
                if s_set[s[begin]] > 1:
                    counter -= 1
                s_set[s[begin]] -= 1
                begin += 1
            m = max(m, end - begin)
        return m





if __name__ == '__main__':
    print(Solution().lengthOfLongestSubstring("abcabcbb"))
    print(Solution().lengthOfLongestSubstring("bbbbb"))
    print(Solution().lengthOfLongestSubstring("pwwkew"))