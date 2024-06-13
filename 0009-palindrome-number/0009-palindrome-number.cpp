class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x<0) return false;
        if(x>=0 and x<=9) return true;
        
        long long revNo = 0;
        int n = x;
        while(n){
            int temp = n%10;
            revNo = (revNo*10)+temp;
            n = n/10;
        }
        return x==int(revNo);
        
    }
};