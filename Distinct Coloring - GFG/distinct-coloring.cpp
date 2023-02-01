//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    long long f(int n, int i, int r[], int g[], int b[], int prev, vector<vector<long long>>&dp)
    {
        if(i>=n) return 0;
        if(dp[i][prev] != -1) return dp[i][prev];
        long long red = 1e11, green = 1e11, blue = 1e11;
        if(prev == 0)
        {
            red = r[i] + f(n, i+1, r, g, b, 1, dp);
            green = g[i] + f(n, i+1, r, g, b, 2, dp);
            blue = b[i] + f(n, i+1, r, g, b, 3, dp);
        }
        else if(prev == 1)
        {
            green = g[i] + f(n, i+1, r, g, b, 2, dp);
            blue = b[i] + f(n, i+1, r, g, b, 3, dp);
        }
        else if(prev == 2)
        {
            red = r[i] + f(n, i+1, r, g, b, 1, dp);
            blue = b[i] + f(n, i+1, r, g, b, 3, dp);
        }
        else
        {
            red = r[i] + f(n, i+1, r, g, b, 1, dp);
            green = g[i] + f(n, i+1, r, g, b, 2, dp);
        }
        return dp[i][prev] = min(red, min(green, blue));
    }

    long long int distinctColoring(int N, int r[], int g[], int b[]){
        int prev = 0;
        vector<vector<long long>>dp(N, vector<long long>(4, -1));
        return f(N, 0, r, g, b, prev, dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends