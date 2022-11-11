class Solution {
public:
    int countSubstrings(string s) {
        vector<string>ans;
        for(int i = 0; i<s.size(); i++)
        {
            string p = "";
            for(int j = i; j<s.size(); j++)
            {
                p += s[j];
                int f = 0;
                for(int k = 0; k<p.size(); k++)
                {
                    if(p[k] != p[p.size()-k-1])
                    {
                        f = 1;
                        break;
                    }
                }
                if(!f) ans.push_back(p);
            }
        }
        return ans.size();
    }
};