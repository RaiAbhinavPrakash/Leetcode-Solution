class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        if(str.size() == 1) return {{str[0]}};
        
        vector<vector<string>>ans;
        map<string,vector<string>>mp;
        for(int i = 0; i<str.size(); i++)
        {
            string k = str[i];
            sort(k.begin(),k.end());
            mp[k].push_back(str[i]);
        }
        for(auto it:mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};