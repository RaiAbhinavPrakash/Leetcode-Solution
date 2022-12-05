class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long int total = 0;
        int n = nums.size();
        for(int i = 0; i<nums.size(); i++)
        {
            total += nums[i];
        }
        int ans = 0;
        long long int sum = 0, diff, k = INT_MAX;
        for(int i = 0; i<nums.size()-1; i++)
        {
            sum += nums[i];
            diff = total-sum;
            if(abs(sum/(1+i)-diff/(n-i-1)) < k)
            {
                ans = i;
                k = abs(sum/(1+i)-diff/(n-i-1));
            }
        }
        
        sum += nums[n-1];
        if(sum/n<k) ans = n-1;
        
        return ans;
        
    }
};