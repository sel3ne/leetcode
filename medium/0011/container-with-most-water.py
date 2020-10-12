class Solution:
    def maxArea(self, height: List[int]) -> int:
        out = 0
        low = 0
        high = len(height) - 1
        while(low < high):
            if(height[low] < height[high]):
                min_height = height[low]
                min_height_index = low
            else:
                min_height = height[high]
                min_height_index = high
            out = max(((high - low)) * min_height, out)
            if(low+1 == min_height_index+1):
                low += 1
            else:
                high -= 1
        return out
