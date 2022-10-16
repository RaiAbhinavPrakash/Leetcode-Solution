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
                    // reverse(s.begin(),s.end());
                    // cnt = stoi(s);
                    for(int x = 0; x<s.size(); x++)
                    {
                        // int rem = cnt%10;
                        // cnt /= 10;
                        k++;
                        // chars[k] = '0'+rem;
                        chars[k] = s[x];
                    }
                }
                k++;
                j = i;
                cnt = 1;
            }
        }
        chars[k] = chars[j];
        // k++;
        if(chars[chars.size()-1] == chars[j])
        {
            if(cnt == 1) k++;
            else if(cnt > 1)
            {
                string s = to_string(cnt);
                // reverse(s.begin(),s.end());
                // cnt = stoi(s);
                for(int x = 0; x<s.size(); x++)
                {
                    // int rem = cnt%10;
                    // cnt /= 10;
                    // cout<<rem<<"\n";
                    k++;
                    // chars[k] = '0'+rem;
                    chars[k] = s[x];
                }
                k++;
            }
            // cout<<chars[j]<<k;
            // chars[k] = chars[j];
            // j++;
        }
        // cout<<j;
        return k;
    }
};