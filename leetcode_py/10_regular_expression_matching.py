import os
import sys
dir_name = os.path.realpath(".")
sys.path.append(dir_name)
from py.utils import check

class Solution:
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        

if __name__ == '__main__':
    check(Solution().isMatch("aa", "a"), False)
    check(Solution().isMatch("aa", "aa"), True)
    check(Solution().isMatch("aaa", "aa"), False)
    check(Solution().isMatch("aa", "a*"), True)
    check(Solution().isMatch("aa", ".*"), True)
    check(Solution().isMatch("ab", ".*"), True)
    check(Solution().isMatch("aab", "c*a*b"), True)