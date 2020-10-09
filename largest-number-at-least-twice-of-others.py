class Solution(object):
    def dominantIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        largest = 0
        second_largest = 0
        for elem in nums:
            if elem > largest:
                second_largest = largest
                largest = elem
            elif elem < largest and elem > second_largest:
                second_largest = elem
        return nums.index(largest) if largest >= 2 * second_largest else -1
