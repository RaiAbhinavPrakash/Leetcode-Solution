//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i, j});
                    grid[i][j] = 3;
                }
            }
        }
        int ans = -1;
        while(q.size())
        {
            int k = q.size();
            for(int i = 0; i<k; i++)
            {
                int a = q.front().first, b = q.front().second;
                q.pop();
                if(a+1<m && grid[a+1][b] == 1)
                {
                    q.push({a+1, b});
                    grid[a+1][b] = 3;
                }
                if(a-1>=0 && grid[a-1][b] == 1)
                {
                    q.push({a-1, b});
                    grid[a-1][b] = 3;
                }
                if(b+1<n && grid[a][b+1] == 1)
                {
                    q.push({a, b+1});
                    grid[a][b+1] = 3;
                }
                if(b-1>=0 && grid[a][b-1] == 1)
                {
                    q.push({a, b-1});
                    grid[a][b-1] = 3;
                }
            }
            ans++;
        }
        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(grid[i][j] == 1) return -1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends