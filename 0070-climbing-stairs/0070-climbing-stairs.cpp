class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 2, sum = 1;
        if(n == 1) return a;
        if(n == 2) return b;
        for(int i = 3; i<=n; i++)
        {
            sum = a+b;
            a = b;
            b = sum;
        }
        return sum;
    }
};