//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minRepeats(string a, string b) {
        map<int,int>mp1;
        for(int i = 0; i<a.size(); i++)
        {
            mp1[a[i]]++;
        }
        for(int i = 0; i<b.size(); i++)
        {
            if(mp1[b[i]] == 0) return -1;
        }
        if(b.size()<a.size()) return -1;
        int ans = 1;
        int f = 0, i = 0;
        for(i = 0; i<a.size(); i++)
        {
            if(a.substr(i, a.size()-i) == b.substr(0, a.size()-i))
            {
                f = 1;
                break;
            }
        }
        if(!f) return -1;
        int j = 0;
        for(int k = a.size()-i; k<b.size(); k++)
        {
            if(b[k] != a[j]) return -1;
            else
            {
                j++;
                if(j == a.size())
                {
                    j = 0;
                    ans++;
                }
            }
        }
        if(j == 0) return ans;
        else return ans+1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends