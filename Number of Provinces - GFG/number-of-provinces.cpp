//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(vector<vector<int>>al, vector<int>&vis, int node)
    {
        vis[node] = 1;
        for(int i = 0; i<al[node].size(); i++)
        {
            if(!vis[al[node][i]]) dfs(al, vis, al[node][i]);
        }
    }
  
    int numProvinces(vector<vector<int>> adj, int v) {
        vector<int>vis(v, 0);
        vector<vector<int>>al(v);
        for(int i = 0; i<v; i++)
        {
            for(int j = 0; j<v; j++)
            {
                if(adj[i][j] == 1 && i != j)
                {
                    al[i].push_back(j);
                    al[j].push_back(i);
                    adj[j][i] = 0;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i<v; i++)
        {
            if(!vis[i])
            {
                ans++;
                dfs(al, vis, i);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends