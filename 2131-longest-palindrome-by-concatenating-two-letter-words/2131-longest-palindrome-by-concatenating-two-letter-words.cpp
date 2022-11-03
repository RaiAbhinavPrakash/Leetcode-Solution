class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int>mp, m;
        for(int i = 0; i<words.size(); i++)
        {
            if(words[i][0] != words[i][1]) mp[words[i]]++;
            else m[words[i]]++;
        }
        int ans = 0;
        for(int i = 0; i<words.size(); i++)
        {
            string s = words[i];
            reverse(s.begin(), s.end());
            if(mp.find(s) != mp.end())
            {
                ans += 4*min(mp[s], mp[words[i]]);
                mp.erase(s);
            }
        }
        int count = 0;
        map<int,int>mc;
        for(auto it:m)
        {
            if(it.second%2 == 0) ans += 2*it.second;
            else
            {
                mc[it.second]++;
                count = max(count, it.second);
            }
        }
        for(auto it:mc)
        {
            if(it.first == count)
            {
                ans += 2*count;
                count--;
                ans += 2*(it.first-1)*(it.second-1);
                break;
            }
            ans += (it.first-1)*it.second*2;
        }
        return ans;
    }
};