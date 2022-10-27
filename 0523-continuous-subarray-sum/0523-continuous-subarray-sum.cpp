class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int,int>m;
        int i;
        m[0] = -1;
        int ans = 0;
        for(i = 0; i<nums.size(); i++)
        {
            ans += nums[i];
            int rem = ans%k;
            if(m.find(rem) != m.end())
            {
                if(i-m[rem]>1) return true;
            }
            else m[rem] = i;
        }
        return false;
    }
};