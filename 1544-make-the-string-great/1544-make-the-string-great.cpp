class Solution {
public:
    string makeGood(string s) {
        while(true)
        {
            int c = 0;
            for(int i = 0; i<s.size(); i++)
            {
                if(abs(s[i]-s[i+1]) == 32)
                {
                    s.erase(i,2);
                }
                else c++;
            }
            if(c == s.size()) break;
        }
        return s;
    }
};