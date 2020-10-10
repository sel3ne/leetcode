class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        num_index = [(v, index) for index, v in enumerate(nums)]
        num_index.sort()
        begin, end = 0, len(nums) - 1
        while(begin < end):
            curr = num_index[begin][0] + num_index[end][0]
            if(curr == target):
                return [num_index[begin][1], num_index[end][1]]
            elif(curr < target):
                begin += 1
            else:
                end -= 1