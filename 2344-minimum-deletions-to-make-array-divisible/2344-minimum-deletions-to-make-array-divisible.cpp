class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        map<int,int>mp;
        int i;
        int gcd = numsDivide[0];
        for(i = 0; i<numsDivide.size(); i++)
        {
            gcd = __gcd(gcd,numsDivide[i]);
        }
        sort(nums.begin(),nums.end());
        for(i = 0; i<nums.size(); i++)
        {
            if(gcd%nums[i] == 0) return i;
        }
        return -1;
    }
};