class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>mp;
        for(int i = 0; i<words.size(); i++) mp[words[i]]++;
        
        map<int,vector<string>>m;
        for(auto it:mp)
        {
            m[it.second].push_back(it.first);
        }
        
        vector<string>ans;
        int c = 0, f = 0;
        for(auto it = m.rbegin(); it!=m.rend(); it++)
        {
            sort(it->second.begin(), it->second.end());
            for(int i = 0; i<(it->second).size(); i++)
            {
                ans.push_back(it->second[i]);
                c++;
                // cout<<c<<"\n";
                if(c == k)
                {
                    f  =1;
                    break;
                }
            }
            if(f) break;
        }
        return ans;
    }
};