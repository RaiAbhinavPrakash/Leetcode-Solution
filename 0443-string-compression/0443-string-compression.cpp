class Solution {
public:
    int compress(vector<char>& chars) {
        int cnt = 1;
        int i, j = 0, k = 0;
        for(i = 1; i<chars.size(); i++)
        {
            if(chars[j] == chars[i]) cnt++;
            else
            {
                chars[k] = chars[j];
                if(cnt > 1)
                {
                    string s = to_string(cnt);
                    for(int x = 0; x<s.size(); x++)
                    {
                        k++;
                        chars[k] = s[x];
                    }
                }
                k++;
                j = i;
                cnt = 1;
            }
        }
        
        chars[k] = chars[j];
        
        if(chars[chars.size()-1] == chars[j])
        {
            if(cnt == 1) k++;
            else if(cnt > 1)
            {
                string s = to_string(cnt);
                for(int x = 0; x<s.size(); x++)
                {
                    k++;
                    chars[k] = s[x];
                }
                k++;
            }
        }
        return k;
    }
};