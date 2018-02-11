from collections import defaultdict

class Solution(object):
    def lengthOfLongestSubstringTwoDistinct(self, s):
        """
        :type s: str
        :rtype: int
        """
        begin, end = 0, 0
        head, m = 0, 0
        counter = 0
        s_set = defaultdict(int)

        while end < len(s):
            if s_set[s[end]] == 0:
                counter += 1
            s_set[s[end]] += 1
            end += 1
            while counter > 2:
                if s_set[s[begin]] == 1:
                    counter -= 1
                s_set[s[begin]] -= 1
                begin += 1
            m = max(m, end - begin)
        return m




if __name__ == '__main__':
    print(Solution().lengthOfLongestSubstringTwoDistinct("eceba"))
    print(Solution().lengthOfLongestSubstringTwoDistinct("abcabcbb"))
    print(Solution().lengthOfLongestSubstringTwoDistinct("bbbbb"))
    print(Solution().lengthOfLongestSubstringTwoDistinct("pwwkew"))