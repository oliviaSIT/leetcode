class Solution:
    """
    @param: : An integer array
    @return: The second max number in the array.

    easy
    Find the second max number in a given array.
    http://www.lintcode.com/en/problem/second-max-of-array/
    """

    def secondMax(self, nums):
        # write your code here
        MaxValue = max(nums[0], nums[1])
        SecValue = min(nums[0], nums[1])

        for i in range(2, len(nums)):
            if nums[i] > MaxValue:
                SecValue = MaxValue
                MaxValue = nums[i]
            elif nums[i] > SecValue:
                SecValue = nums[i]

        return SecValue

