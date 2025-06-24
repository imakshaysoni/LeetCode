class Solution:
    def divideString(self, s: str, k: int, fill: str) -> List[str]:
        i=0
        ans = []
        while i+k < len(s):
            ch = s[i:i+k]
            ans.append(ch)
            i = i+k
        ch = ""
        while i < len(s):
            ch += s[i]
            i+=1
        while(len(ch) < k):
            ch += fill
        ans.append(ch)
        return ans
        