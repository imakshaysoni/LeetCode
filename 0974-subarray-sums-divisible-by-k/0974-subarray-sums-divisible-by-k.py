class Solution(object):
    def subarraysDivByK(self, A, K):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        sums = {0: 1}
        count = 0
        running_sum = 0
        for i in range(len(A)):
            running_sum = (running_sum + A[i]) % K
            if running_sum in sums:
                count += sums[running_sum]
                sums[running_sum] += 1
            else:
                sums[running_sum] = 1
        return count
