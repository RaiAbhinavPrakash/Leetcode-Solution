//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    long long getMin(long long A[], long long B[], long long n)
    {
        if(n == 1) return -1;
        int idx1, idx2;
        long long a = A[0], b = B[0];
        for(int i = 0; i<n; i++)
        {
            if(A[i]<=a)
            {
                a = A[i];
                idx1 = i;
            }
            if(B[i]<=b)
            {
                b = B[i];
                idx2 = i;
            }
        }
        sort(A, A+n);
        sort(B, B+n);
        if(idx1 != idx2) return A[0]+B[0];
        else return min(A[0]+B[1], A[1]+B[0]);
    }
};

//{ Driver Code Starts.

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        long long n, i;
        cin>>n;
        long long A[n+1], B[n+1];
        for(i=0;i<n;i++)
        cin>>A[i];
    
        for(i=0;i<n;i++)
        cin>>B[i];
        Solution ob;
        cout<< ob.getMin(A, B, n) <<endl;
    }
}

// } Driver Code Ends