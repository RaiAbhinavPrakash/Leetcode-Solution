//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int f(int price[], int n, int i, vector<vector<int>>&dp)
    {
        if(i == 0)
        {
            return n*price[0];
        }
        if(dp[n][i] != -1) return dp[n][i];
        int notTake = 0+f(price, n, i-1, dp);
        int take = INT_MIN;
        if(n>i)
        {
            take = price[i]+f(price, n-i-1, i, dp);
        }
        return dp[n][i] = max(take, notTake);
    }
  
    int cutRod(int price[], int n) {
        int i = n-1;
        vector<vector<int>>dp(n+1, vector<int>(n,-1));
        return f(price, n, i, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends