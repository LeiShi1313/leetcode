class Solution:
    def removeInvalidParentheses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        left, right, pair = 0, 0, 0
        for c in s:
            if c == '(':
                left += 1
            elif c == ')':
                if left > 0:
                    left -= 1
                else:
                    right += 1
        res = set()
        self.helper(0, 0, left, right, s, "", res)
        return list(res)

    def helper(self, pair, idx, left, right, s, cur, res):
        if idx == len(s):
            if pair == 0 and left == 0 and right == 0:
                res.add(cur)
            return

        if s[idx] == '(':
            if left > 0:
                self.helper(pair, idx+1, left-1, right, s, cur, res)
            self.helper(pair+1, idx+1, left, right, s, cur+'(', res)
        elif s[idx] == ')':
            if right > 0:
                self.helper(pair, idx+1, left, right-1, s, cur, res)
            if pair > 0:
                self.helper(pair-1, idx+1, left, right, s, cur+')', res)
        else:
            self.helper(pair, idx+1, left, right, s, cur+s[idx], res)



if __name__ == '__main__':
    print(Solution().removeInvalidParentheses(")()m)(((()((()(((("))
    print(Solution().removeInvalidParentheses("()())()"))
    print(Solution().removeInvalidParentheses("(a)())()"))
    print(Solution().removeInvalidParentheses(")("))
    print(Solution().removeInvalidParentheses("()"))
    print(Solution().removeInvalidParentheses("n"))