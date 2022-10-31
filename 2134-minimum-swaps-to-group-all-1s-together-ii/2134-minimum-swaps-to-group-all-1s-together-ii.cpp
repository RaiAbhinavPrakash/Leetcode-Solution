class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int ans = INT_MAX;
        int ones = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i] == 1) ones++;
        }
        int i, one = 0, j = 0;
        for(i = 0; i<nums.size(); i++)
        {
            if(nums[i] == 1) one++;
            if((i-j+1) == ones)
            {
                ans = min(ans, ones-one);
                if(nums[j] == 1) one--;
                j++;
            }
        }
        i = 0;
        while(j != nums.size())
        {
            if(nums[i] == 1) one++;
            ans = min(ans, ones-one);
            // cout<<ones<<" "<<one<<" "<<i<<" "<<j<<"\n";
            if(nums[j] == 1) one--;
            j++;
            i++;
        }
        return ans;
    }
};