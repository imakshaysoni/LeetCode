class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        int p = pow(2, 31)-1;
        cout<<p;
        while(x){
            int n = x%10;
            if(ans > p/10 || ans < -p/10) return 0; 
            ans = ans*10 + n;
            x = x/10;
        }
        return ans;

    }
};