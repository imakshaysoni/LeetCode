class Solution:
    def maxArea(self, height: List[int]) -> int:
        
        n = len(height)
        start = 0
        end = n-1
        max_output = 0
        while(start<end):
            max_output = max(max_output,
                             min(height[start], height[end]) * (end-start)
                            )
            if(height[start]<height[end]):
                start+=1
            else:
                end-=1
            
        return max_output
        