//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isPossible(int n, int m, string s){
        int r = 0, c = 0, xmin = 0, ymin = 0, xmax = 0, ymax = 0;
        for(int i = 0; i<s.size(); i++)
        {
            if(s[i] == 'L')
            {
                c--;
                if(c<0)
                {
                    ymin = max(ymin, abs(c));
                }
            }
            else if(s[i] == 'R')
            {
                c++;
                if(c>=m) return 0;
                ymax = max(ymax, c);
            }
            else if(s[i] == 'U')
            {
                r++;
                if(r>=n) return 0;
                xmax = max(r, xmax);
            }
            else if(s[i] == 'D')
            {
                r--;
                if(r<0)
                {
                    xmin = max(xmin, abs(r));
                }
            }
        }
        if(xmax+xmin+1>n || ymax+ymin+1>m) return 0;
        return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.isPossible(n, m, s)<<endl;
    }
    return 0;
}
// } Driver Code Ends