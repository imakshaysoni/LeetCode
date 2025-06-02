class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> days(n+1, 0);
        int mod = 1e9+7;
        days[1] = 1;
        for(int i=1;i<=n;i++){
            if(days[i]==0) continue;
            for(int j=i+delay;j<i+forget and j<=n ;j++){
                days[j] = (days[i]+days[j])%mod;
            }
            // if(i+forget <=  n and days[i]>0) days[i] = (days[i] - 1)%mod;
        }
        int count = 0;
        for (int i = n - forget + 1; i <= n; ++i) {
            count = (count + days[i]) % mod;
        }
        return count%mod;

    }
};