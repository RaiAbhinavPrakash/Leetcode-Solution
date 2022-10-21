class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,vector<int>>mp;
        int ans = INT_MAX;
        for(int i = 0; i<nums.size(); i++)
        {
            if(mp[nums[i]].size()>=1)
            {
                ans = min(ans,i+1-mp[nums[i]][mp[nums[i]].size()-1]);
            }
            mp[nums[i]].push_back(i+1);
        }
        if(ans <= k) return true;
        return false;
    }
};