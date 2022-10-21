//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int mod = 1e8;
    int fillingBucket(int N) {
        if(N == 1) return 1;
        if(N == 2) return 2;
        int a = 1, b = 2;
        for(int i = 3; i<=N; i++)
        {
            int c = b;
            b = (b+a)%mod;
            a = c;
        }
        return b;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends