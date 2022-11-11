class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        map<int,int>mp;
        int i = 0, j = 0;
        for(i = 0; i<v.size(); i++)
        {
            if(mp[v[i]] == 0)
            {
                v[j] = v[i];
                mp[v[i]]++;
                j++;
            }
            else
            {
                continue;
            }
        }
        return j;
    }
};