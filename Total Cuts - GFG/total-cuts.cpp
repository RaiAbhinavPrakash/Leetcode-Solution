//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int N,int K,vector<int> &A){
        if(N == 1) return 0;
        vector<int>max, min;
        int currMax = A[0], currMin = A[N-1];
        for(int i = 0; i<N-1; i++)
        {
            if(A[i]>=currMax)
            {
                max.push_back(A[i]);
                currMax = A[i];
            }
            else max.push_back(currMax);
        }
        for(int i = N-1; i>0; i--)
        {
            if(A[i]<=currMin)
            {
                min.push_back(A[i]);
                currMin = A[i];
            }
            else min.push_back(currMin);
        }
        int ans = 0;
        for(int i = 0; i<N-1; i++)
        {
            if(max[i]+min[min.size()-i-1] >= K) ans++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends