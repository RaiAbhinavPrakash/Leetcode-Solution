class Solution {
public:
    string removeDuplicates(string s) {
        while(true)
        {
            int c = 0;
            for(int i = 0; i<s.size(); i++)
            {
                if(s[i] == s[i+1])
                {
                    s.erase(i, 2);
                    i--; i--;
                    if(i == -2) i = -1;
                }
                else c++;
            }
            if(c == s.size()) break;
        }
        return s;
    }
};