from collections import defaultdict
from copy import deepcopy


class Solution(object):
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        if not s or not words:
            return []
        word_len = len(words[0])
        total_len = len(words) * word_len
        words_count = defaultdict(int)
        for word in words:
            words_count[word] += 1

        idx = 0
        res = []
        while idx + total_len <= len(s):
            if s[idx:idx + word_len] in words_count:
                words_count_copy = defaultdict(int)
                start = idx
                end = idx + total_len
                while start < end and \
                        s[start:start + word_len] in words_count and \
                        s[end - word_len:end] in words_count:
                    words_count_copy[s[start:start + word_len]] += 1
                    if words_count_copy[s[start:start + word_len]] > words_count[s[start:start + word_len]]:
                        break
                    if end - word_len != start:
                        words_count_copy[s[end - word_len:end]] += 1
                        if words_count_copy[s[end - word_len:end]] > words_count[s[end - word_len:end]]:
                            break
                    start += word_len
                    end -= word_len
                if start >= end:
                    res.append(idx)
            idx += 1
        return res

if __name__ == '__main__':
    print Solution().findSubstring("abababab", ["a","b","a"])
    print Solution().findSubstring("barfoothefoobarman", ["foo","bar"])