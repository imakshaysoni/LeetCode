class Solution:
    def fib(self, n: int) -> int:

        dp = [-1 for _ in range(0, n+1)]
        return self.solve(n, dp)
    
    def solve(self, n, dp):
        if(n==0): return 0
        if(n==1): return 1

        dp[n] = self.solve(n-1, dp) + self.solve(n-2, dp)
        return dp[n]
        