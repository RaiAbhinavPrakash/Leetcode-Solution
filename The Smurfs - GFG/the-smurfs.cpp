//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int findMin(int n, char a[]){
        map<char,int>mp;
        for(int i = 0; i<n; i++)
        {
            mp[a[i]]++;
        }
        if(mp.size() == 1) return n;
        int x = mp['R'], y = mp['G'], z = mp['B'];
        if(x == 0)
        {
            if(y%2 == 0 && z%2 == 0) return 2;
            else return 1;
        }
        if(y == 0)
        {
            if(x%2 == 0 && z%2 == 0) return 2;
            else return 1;
        }
        if(z == 0)
        {
            if(x%2 == 0 && y%2 == 0) return 2;
            else return 1;
        }
        if(x%2 == 1 && y%2 == 1 && z%2 == 1) return 2;
        int o = 0, e = 0;
        if(x%2 == 1)
        {
            o++;
        }
        if(y%2 == 1)
        {
            o++;
        }
        if(z%2 == 1)
        {
            o++;
        }
        if(o == 3) return 2;
        if(o == 2) return 1;
        if(o == 1) return 1;
        if(o == 0) return 2;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        cout<<ob.findMin(n, a)<<"\n";
    }
    return 0;
}
// } Driver Code Ends