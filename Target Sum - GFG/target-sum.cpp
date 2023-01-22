//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int f(vector<int>v, int n, int target, map<pair<int,int>,int>&dp)
    {
        if(target == 0 && n<0)
        {
            return 1;
        }
        if(n<0) return 0;
        if(dp.find({n, target}) != dp.end()) return dp[{n, target}];
        int minus = f(v, n-1, target-v[n], dp);
        int plus = f(v, n-1, target+v[n], dp);
        return dp[{n, target}] = plus+minus;
    }
    
    int findTargetSumWays(vector<int>&v ,int target) {
        int n = v.size();
        int ans = 0, sum = 0;
        map<pair<int,int>, int>dp;
        return f(v, n-1, target, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends