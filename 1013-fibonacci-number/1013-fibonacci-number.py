class Solution:
    dp = [-1 for _ in range(0, 30+2)]
    def fib(self, n: int) -> int:
        if n==0: return 0
        if n==1: return 1

        if(Solution.dp[n]!=-1): return Solution.dp[n]
        Solution.dp[n] = self.fib(n-1) + self.fib(n-2)
        return Solution.dp[n]
        