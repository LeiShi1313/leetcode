class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1
        
        m, n = len(nums1), len(nums2)
        if n == 0:
            return -1
        if m == 0:
            return (nums2[n // 2] + nums2[(n-1) // 2]) / 2

        lo, hi = 0, 2 * m
        while lo <= hi:
            mid1 = (lo + hi) // 2
            mid2 = m+n - mid1
            
            L1 = nums1[(mid1-1) // 2] if mid1 != 0 else float('-inf')
            R1 = nums1[mid1 // 2] if mid1 != 2*m else float('inf')
            L2 = nums2[(mid2-1) // 2] if mid2 != 0 else float('-inf')
            R2 = nums2[mid2 // 2] if mid2 != 2*n else float('inf')

            if L1 > R2:
                hi = mid1
            elif L2 > R1:
                lo = mid1 + 1
            else:
                return (max(L1, L2) + min(R1, R2)) / 2
        return -1


        


if __name__ == '__main__':
    print(Solution().findMedianSortedArrays([1, 2], [3, 4]))
    print(Solution().findMedianSortedArrays([1, 3], [2, 4]))
    print(Solution().findMedianSortedArrays([1, 2], [1, 2, 3]))