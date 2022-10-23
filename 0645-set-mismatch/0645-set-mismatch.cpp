class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int f = 1;
        map<int,int>mp;
        vector<int>ans(2);
        for(int i = 0; i<nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        int c = 0;
        for(auto it:mp)
        {
            if(it.second == 2) ans[0] = it.first;
            if(f && it.first != c+1)
            {
                ans[1] = c+1;
                f = 0;
            }
            c++;
        }
        if(ans[1] == 0) ans[1] = nums.size();
        return ans;
    }
};