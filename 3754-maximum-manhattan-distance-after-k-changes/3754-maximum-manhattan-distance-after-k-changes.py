class Solution:
    def maxDistance(self, s: str, k: int) -> int:

        ideal_dist: int = len(s)
        north, south, east, west = 0,0,0,0
        max_dist = -1e9
        count=1;
        for direction in s:
            if direction=='N': north+=1
            if direction=='S': south+=1
            if direction=='E': east+=1
            if direction=='W': west+=1
            curr_dist = abs(north-south) + abs(east-west)
            wasted_steps = count - curr_dist
            extra_steps = min(wasted_steps, 2*k)
            max_dist = max(curr_dist+extra_steps, max_dist)
            count+=1
        return max_dist
            
        