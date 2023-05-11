//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumSum(string s) {
        int i = 0, j = s.size()-1;
        while(i<=j)
        {
            if(s[i] != '?' && s[j] == '?')
            {
                s[j] = s[i];
            }
            else if(s[i] == '?' && s[j] != '?')
            {
                s[i] = s[j];
            }
            else if(s[i] != '?' && s[j] != '?' && s[i] != s[j]) return -1;
            i++; j--;
        }
        int ans = 0;
        char first = '.';
        for(int i = 0; i<s.size(); i++)
        {
            if(s[i] == '?') continue;
            else
            {
                if(first == '.') first = s[i];
                else
                {
                    ans += abs(s[i]-first);
                    first = s[i];
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends