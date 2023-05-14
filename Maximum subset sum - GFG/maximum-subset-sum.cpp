//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class IntArray
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {

  public:
    long long f(vector<int>&a, int n, int i, vector<long long>&dp)
    {
        if(i>=n) return 0;
        if(dp[i] != -1) return dp[i];
        int one = a[i]+f(a, n, i+1, dp);
        int two = a[i]+f(a, n, i+2, dp);
        return dp[i] = max(one, two);
    }
  
    long long findMaxSubsetSum(int n, vector<int> &a) {
        vector<long long>dp(n, -1);
        return max(f(a, n, 0, dp), f(a, n, 1, dp));
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        IntArray::input(A,N);
        
        Solution obj;
        long long res = obj.findMaxSubsetSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends