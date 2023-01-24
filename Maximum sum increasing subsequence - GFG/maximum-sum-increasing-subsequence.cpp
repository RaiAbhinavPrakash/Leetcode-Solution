//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    int f(int arr[], int n, vector<vector<int>>&dp, int prev)
    {
        if(n<0)
        {
            return 0;
        }
        if(dp[n][prev+1] != -1) return dp[n][prev+1];
        if(prev == -1  ||  arr[n]<arr[prev])
        {
            int take = arr[n]+f(arr, n-1, dp, n);
            int notTake = 0+f(arr, n-1, dp, prev);
            return dp[n][prev+1] = max(take, notTake);
        }
        return dp[n][prev+1] = f(arr, n-1, dp, prev);
    }
    
	int maxSumIS(int arr[], int n)  
	{  
	    vector<vector<int>>dp(n, vector<int>(n+1, -1));
	    int prev = -1;
	    return f(arr, n-1, dp, prev);
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

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends