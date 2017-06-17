class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        nums.sort()
        l = []
        for i in xrange(len(nums)-3):
            if i>0 and nums[i] == nums[i-1]:
                continue
            for j in xrange(i+1, len(nums)-2):
                if j > i+1 and nums[j] == nums[j-1]:
                    continue
                twoSumL = self.twoSum(nums[j+1:], target-nums[i]-nums[j])
                if len(twoSumL) > 0:
                    map(lambda(x): l.append([nums[i], nums[j]]+x), twoSumL)
        return l

    def twoSum(self, nums, target):
        d = {}
        l = []
        i = 0
        j = len(nums) - 1
        while (i < j):
            left = target - nums[i] - nums[j]
            if (left > 0):
                i += 1
            elif (left < 0):
                j -= 1
            else:
                l.append([nums[i], nums[j]])
                while i<j and nums[i] == nums[i+1]:
                    i += 1
                while i<j and nums[j] == nums[j-1]:
                    j -= 1
                i += 1
                j -= 1
        return l



print Solution().fourSum([-2,0,0,3,3,-1], 5)
