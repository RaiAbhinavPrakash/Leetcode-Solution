//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int val[], int wt[], int w, int i, int n, vector<vector<int>>&dp)
    {
        if(i>n) return 0;
        if(dp[i][w] != -1) return dp[i][w];
        int a = 0, b = 0, c = 0;
        if(wt[i]<=w)
        {
            a = val[i]+f(val, wt, w-wt[i], i+1, n, dp);
            b = val[i]+f(val, wt, w-wt[i], i, n, dp);
        }
        c = f(val, wt, w, i+1, n, dp);
        return dp[i][w] = max(a, max(b, c));
    }

    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>>dp(N, vector<int>(W+1, -1));
        return f(val, wt, W, 0, N-1, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends