def longestCommonPrefix(strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if not strs:
            return ""
        l = []
        m = min([len(s) for s in strs])
        for i in xrange(m):
            if all(s[i]==strs[0][i] for s in strs):
                l.append(s[i])
            else:
                break
        return ''.join(l)

print longestCommonPrefix(["aca","cba"])
