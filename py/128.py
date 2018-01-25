class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        mem = {}
        longest = 0
        for num in nums:
            if num in mem:
                continue
            else:
                if num-1 not in mem and num+1 not in mem:
                    mem[num] = 1
                elif num-1 not in mem:
                    v = mem[num+1] + 1
                    mem[num+mem[num+1]] = v
                    mem[num] = v
                elif num+1 not in mem:
                    v = mem[num-1] + 1
                    mem[num-mem[num-1]] = v
                    mem[num] = v
                else:
                    v = mem[num-1] + mem[num+1] + 1
                    mem[num+mem[num+1]] = v
                    mem[num-mem[num-1]] = v
                    mem[num] = v
                longest = max(longest, mem[num])
        return longest

if __name__ == '__main__':
    print Solution().longestConsecutive([100,4,200,1,3,2])