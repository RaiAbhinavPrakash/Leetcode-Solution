class Solution {
public:
    int divide(int dividend, int divisor) {
        int m = INT_MIN, M = INT_MAX;
        int ans;
        if(dividend == m && divisor == -1) ans = M;
        else ans = dividend / divisor;
        return ans;
    }
};