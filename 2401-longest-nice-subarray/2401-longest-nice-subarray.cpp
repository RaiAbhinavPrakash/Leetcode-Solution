class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        vector<int>v;
        v.push_back(nums[0]);
        int ans = 1;
        for(int i = 0; i<nums.size(); i++)
        {
            v.push_back(nums[i]);
            int f = 0;
            for(int j = 0; j<v.size(); j++)
            {
                for(int k = j+1; k<v.size(); k++)
                {
                    if(v[j]&v[k])
                    {
                        f = 1;
                        break;
                    }
                }
                if(f)
                {
                    v.erase(v.begin());
                    break;
                }
            }
            if(!f)
            {
                if(v.size()>ans) ans = v.size();
            }
        }
        return ans;
    }
};