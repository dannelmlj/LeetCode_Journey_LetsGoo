class Solution:
    def maxArea(self, height: List[int]) -> int:
        mostWater = 0
        left = 0
        right = len(height) - 1

        while left < right:
            currentArea = min(height[left],height[right]) * (right-left)
            mostWater = max(mostWater,currentArea)
            if height[left] < height[right]:
                left += 1
            else: right -=1

        return mostWater
        