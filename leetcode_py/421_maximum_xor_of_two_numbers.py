class Solution:
    def findMaximumXOR(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        answer = 0
        for i in range(32)[::-1]:
            answer <<= 1
            prefixes = {num >> i for num in nums}
            answer += any(answer^1 ^ p in prefixes for p in prefixes)
        return answer

if __name__ == '__main__':
    print(Solution().findMaximumXOR([3, 10, 5, 2, 8]))
    print(Solution().findMaximumXOR([8, 4, 2, 1]))