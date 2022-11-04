class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int>num;
        int j = 0, f = 1;
        for(int i = 0; i<nums.size()/2; i++)
        {
            if(f)
            {
                num.push_back(min(nums[i+j], nums[i+j+1]));
                f = 0;
            }
            else
            {
                num.push_back(max(nums[i+j], nums[i+j+1]));
                f = 1;
            }
            j++;
        }
        return minMaxGame(num);
    }
};