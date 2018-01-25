
class Solution(object):
    def wordPatternMatch(self, pattern, s):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        match = {}
        for i in range(26):
            match[chr(ord('a' ) +i)] = ''
        return self.matchPattern(pattern, s, match)

    def matchPattern(self, pattern, s, match):
        print pattern, s
        if not pattern and not s:
            return True
        elif not pattern or not s:
            return False
        print not pattern, not s
        for i in range(1, len(s) + 1):
            if not match[pattern[0]]:
                match[pattern[0]] = s[0:i]
                if self.matchPattern(''.join(pattern.split(pattern[0])),
                                     ''.join(s.split(s[0:i])),
                                     match):
                    return True
                else:
                    match[pattern[0]] = ''
        return False

if __name__ == '__main__':
    print Solution().wordPatternMatch("abab", "redblueredblue")
    print Solution().wordPatternMatch("ats", "ataa")
