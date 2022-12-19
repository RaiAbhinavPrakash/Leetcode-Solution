//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int check(string s, int left, int right)
    {
        if(s.size()<1) return 0;
        while(left>=0 && right<s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }
        return right-left-1;
    }
    
    string longestPalin (string s) {
        int start = 0, end = 0;
        for(int i = 0; i<s.size(); i++)
        {
            int k, check1 = check(s, i, i), check2 = check(s, i, i+1);
            k = max(check1, check2);
            if(k>end-start+1)
            {
                start = i-((k-1)/2);
                end = i+k/2;
            }
        }
        string ans = s.substr(start, end-start+1);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends