//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
bool compare(string &s1, string &s2)
{
    if(s1.size()<s2.size())
    {
        return true;
    }
    else if(s1.size()>s2.size())
    {
        return false;
    }
    else return s1<s2;
}

class Solution
{
public:

    string longestString(vector<string> &words)
    {
        map<string, int>mp;
        for(int i = 0; i<words.size(); i++)
        {
            mp[words[i]]++;
        }
        sort(words.begin(), words.end(), compare);
        string ans = "";
        for(int i = 0; i<words.size(); i++)
        {
            string p = "";
            int j;
            for(j = 0; j<words[i].size(); j++)
            {
                p += words[i][j];
                if(mp.find(p) == mp.end()) break;
            }
            if(j == words[i].size())
            {
                if(p.size()>ans.size()) ans = p;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends