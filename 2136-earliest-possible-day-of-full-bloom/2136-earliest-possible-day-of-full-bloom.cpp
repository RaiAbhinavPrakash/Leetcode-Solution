class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>>v;
        for(int i = 0; i<plantTime.size(); i++)
        {
            v.push_back({growTime[i], plantTime[i]});
        }
        sort(v.begin(), v.end());
        int sum = v[v.size()-1].second-1;
        int ans = sum + v[v.size()-1].first+1;
        int tot = sum + v[v.size()-1].first+1;
        for(int i = v.size()-2; i>=0; i--)
        {
            sum += v[i].second;
            tot = sum + v[i].first+1;
            ans = max(ans, tot);
        }
        return ans;
    }
};