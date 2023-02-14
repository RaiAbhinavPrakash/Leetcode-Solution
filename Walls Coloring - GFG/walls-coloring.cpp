//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int f(vector<vector<int>>&colors, int n, int prev, int i, vector<vector<int>>&dp)
    {
        if(i>n) return 0;
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        int pink = INT_MAX, black = INT_MAX, yellow = INT_MAX;
        if(prev == -1)
        {
            pink = colors[i][0] + f(colors, n, 0, i+1, dp);
            black = colors[i][1] + f(colors, n, 1, i+1, dp);
            yellow = colors[i][2] + f(colors, n, 2, i+1, dp);
        }
        else if(prev == 0)
        {
            black = colors[i][1] + f(colors, n, 1, i+1, dp);
            yellow = colors[i][2] + f(colors, n, 2, i+1, dp);
        }
        else if(prev == 1)
        {
            pink = colors[i][0] + f(colors, n, 0, i+1, dp);
            yellow = colors[i][2] + f(colors, n, 2, i+1, dp);
        }
        else if(prev == 2)
        {
            pink = colors[i][0] + f(colors, n, 0, i+1, dp);
            black = colors[i][1] + f(colors, n, 1, i+1, dp);
        }
        return dp[i][prev+1] = min(pink, min(black, yellow));
    }

    int minCost(vector<vector<int>> &colors, int n) {
        int prev = -1;
        vector<vector<int>>dp(n, vector<int>(4, -1));
        return f(colors, n-1, prev, 0, dp);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends