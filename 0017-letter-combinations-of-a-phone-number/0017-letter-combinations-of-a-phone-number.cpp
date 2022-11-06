class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char,vector<string>>mp;
        mp = {{'2', {"a", "b", "c"}}, {'3', {"d", "e", "f"}}, {'4', {"g", "h", "i"}}, {'5', {"j", "k", "l"}}, {'6', {"m", "n", "o"}}, {'7', {"p", "q", "r", "s"}}, {'8', {"t", "u", "v"}}, {'9', {"w", "x", "y", "z"}}};
        
        vector<string>ans;
        if(digits.size() == 0) return ans;
        if(digits.size() == 1)
        {
            for(int i = 0; i<mp[digits[0]].size(); i++)
            {
                ans.push_back(mp[digits[0]][i]);
            }
        }
        else if(digits.size() == 2)
        {
            for(int i = 0; i<mp[digits[0]].size(); i++)
            {
                string s = mp[digits[0]][i];
                for(int j = 0; j<mp[digits[1]].size(); j++)
                {
                    ans.push_back(s+mp[digits[1]][j]);
                }
            }
        }
        else if(digits.size() == 3)
        {
            for(int i = 0; i<mp[digits[0]].size(); i++)
            {
                string s = mp[digits[0]][i];
                for(int j = 0; j<mp[digits[1]].size(); j++)
                {
                    for(int k = 0; k<mp[digits[2]].size(); k++)
                    {
                        ans.push_back(s+mp[digits[1]][j]+mp[digits[2]][k]);
                    }
                }
            }
        }
        else
        {
            for(int i = 0; i<mp[digits[0]].size(); i++)
            {
                string s = mp[digits[0]][i];
                for(int j = 0; j<mp[digits[1]].size(); j++)
                {
                    for(int k = 0; k<mp[digits[2]].size(); k++)
                    {
                        for(int l = 0; l<mp[digits[3]].size(); l++)
                        {
                            ans.push_back(s+mp[digits[1]][j]+mp[digits[2]][k]+mp[digits[3]][l]);
                        }
                    }
                }
            }
        }
        return ans;
        
    }
};