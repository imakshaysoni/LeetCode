class Solution:
    def minimumDeletions(self, word: str, k: int) -> int:
        mapp = {}
        for i in word:
            if i not in mapp:
                mapp[i]=1
            else:
                mapp[i]+=1
        mini = 1e9
        
        for key, value in mapp.items():
            cnt = 0
            for k1, v1 in mapp.items():
                if(k1==key): continue
                diff = abs(v1-value)
                # if diff > k:
                #     cnt += diff-k
                if v1 < value:
                    cnt += v1  # delete entire character
                elif v1 - value > k:
                    cnt += v1 - (value + k) 
            mini = min(mini, cnt)
        return mini   

        