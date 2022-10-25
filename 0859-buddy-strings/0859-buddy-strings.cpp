class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size()) return false;
        int ans = 0;
        map<char,int>mp1,mp2;
        for(int i = 0; i<s.size(); i++)
        {
            mp1[s[i]]++;
            mp2[goal[i]]++;
        }
        for(int i = 0; i<s.size(); i++)
        {
            if(mp1[s[i]] != mp2[s[i]]){
                return false;
            }
        }
        map<pair<char,char>,int>m;
        for(int i = 0; i<s.size(); i++)
        {
            if(s[i] != goal[i]) ans++;
            else if(s[i] == goal[i])
            {
                m[{s[i], goal[i]}]++;
            }
        }
        if(ans == 2) return true;
        if(ans>2) return false;
        for(auto it:m)
        {
            if(it.second >= 2) return true;
        }
        return false;
    }
};