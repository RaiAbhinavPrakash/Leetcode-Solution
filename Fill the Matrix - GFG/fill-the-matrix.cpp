//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int N, int M, int x, int y){    
        vector<vector<int>>mat(N, vector<int>(M, 0));
        mat[x-1][y-1] = 1;
        queue<pair<int,int>>q;
        q.push({x-1, y-1});
        int ans = -1;
        while(q.size())
        {
            int k = q.size();
            ans++;
            for(int i = 0; i<k; i++)
            {
                int a = q.front().first;
                int b = q.front().second;
                q.pop();
                if(a-1>=0 && mat[a-1][b] == 0)
                {
                    mat[a-1][b] = 1;
                    q.push({a-1, b});
                }
                if(a+1<N && mat[a+1][b] == 0)
                {
                    mat[a+1][b] = 1;
                    q.push({a+1, b});
                }
                if(b-1>=0 && mat[a][b-1] == 0)
                {
                    mat[a][b-1] = 1;
                    q.push({a, b-1});
                }
                if(b+1<M && mat[a][b+1] == 0)
                {
                    mat[a][b+1] = 1;
                    q.push({a, b+1});
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends