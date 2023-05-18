//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int closedIslands(vector<vector<int>>& matrix, int n, int m) {
        queue<pair<int,int>>q;
        int ans = 0;
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                if(i>0 && i<n-1 && j>0 && j<m-1)
                {
                    if(matrix[i][j] == 1)
                    {
                        int f = 1;
                        matrix[i][j] = 0;
                        q.push({i, j});
                        while(q.size())
                        {
                            int k = q.size();
                            while(k--)
                            {
                                int a = q.front().first, b = q.front().second;
                                q.pop();
                                if(a+1<n && matrix[a+1][b] == 1)
                                {
                                    if(a+1 == n-1) f = 0;
                                    matrix[a+1][b] = 0;
                                    q.push({a+1, b});
                                }
                                if(a-1>=0 && matrix[a-1][b] == 1)
                                {
                                    if(a-1 == 0) f = 0;
                                    matrix[a-1][b] = 0;
                                    q.push({a-1, b});
                                }
                                if(b+1<m && matrix[a][b+1] == 1)
                                {
                                    if(b+1 == m-1) f = 0;
                                    matrix[a][b+1] = 0;
                                    q.push({a, b+1});
                                }
                                if(b-1>=0 && matrix[a][b-1] == 1)
                                {
                                    if(b-1 == 0) f = 0;
                                    matrix[a][b-1] = 0;
                                    q.push({a, b-1});
                                }
                            }
                        }
                        if(f) ans++;
                    }
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends