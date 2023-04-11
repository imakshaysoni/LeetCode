// class Solution {
// public:
//     double myPow(double x, int n) {
//         vector<int> dp;
        
//         if (n == INT_MAX) return (x == 1) ? 1 : (x == -1) ? -1 : 0;
//         if (n == INT_MIN) return (x == 1 || x == -1) ? 1 : 0;
//         if (n< 0 ) {
//             n = abs(n);
//             x = 1/x;
//         };
//         return pow(x,n);    
//     }
    
//     double pow(double x, int n){     
//         if(n==0) return 1;
//         double temp = pow(x,n/2);
//         if(n%2==1) return x*temp*temp;
//         return temp*temp;
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
        double temp = myPow(x,n/2);
        if(n%2==0){
            return temp*temp;
        }
        else{
            return x*temp*temp;
        }
    }
};
