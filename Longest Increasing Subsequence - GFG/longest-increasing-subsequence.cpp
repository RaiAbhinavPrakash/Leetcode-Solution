//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
  public:
    int f(int a[], int n, int prev, vector<vector<int>>&dp)
    {
        if(n<0) return 0;
        if(dp[n][prev+1] != -1) return dp[n][prev+1];
        if(prev == -1 || a[prev]>a[n])
        {
            int take = 1 + f(a, n-1, n, dp);
            int notTake = 0 + f(a, n-1, prev, dp);
            return dp[n][prev+1] = max(take, notTake);
        }
        else return f(a, n-1, prev, dp);
    }
    
    int longestSubsequence(int n, int a[])
    {
       int prev = -1;
       vector<vector<int>>dp(n, vector<int>(n+1, -1));
       return f(a, n-1, prev, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends