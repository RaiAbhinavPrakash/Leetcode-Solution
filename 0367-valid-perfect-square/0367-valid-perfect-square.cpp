class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1) return true;
        for(int i = 2; i<=num; i++)
        {
            if(num%i == 0  &&  num/i == i) return true;
            if(num/i < i) break;
        }
        return false;
    }
};