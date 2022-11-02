class Solution {
public:
    int check(int n, bool f)
    {
        if(n == 1) return 1;
        if(f || n%2)
        {
            return 2*check(n/2, !f);
        }
        return 2*check(n/2, !f) - 1;
    }
    int lastRemaining(int n) {
        bool f = true;
        return check(n, f);
    }
};