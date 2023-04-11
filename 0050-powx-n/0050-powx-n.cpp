// class Solution {
// public:
//     double myPow(double x, int n) {
//         vector<int> dp;
        
//         if (n == INT_MAX) return (x == 1) ? 1 : (x == -1) ? -1 : 0;
//         if (n == INT_MIN) return (x == 1 || x == -1) ? 1 : 0;
//         if (n< 0 ) return 1.0/pow(x,abs(n));
//         return pow(x,n);    
//     }
    
//     double pow(double x, int n){     
//         if(n==0) return 1;     
//         return x * pow(x,n-1);
//     }
// };

class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(n<0) {
            n = abs(n);
            x = 1/x;
        }
        if(n%2==0){
            return myPow(x*x, n/2);
        }
        else{
            return x*myPow(x, n-1);
        }
    }
};
