class Solution {
public:
    int differenceOfSums(int n, int m) {
        int totsum = (n*(n+1))/2;
        int x = n/m;
        int divisibleSum = (x*(x+1))/2;
        cout<<totsum<<":"<<x<<":"<<divisibleSum;
        return totsum - 2*m*divisibleSum;
    }
};