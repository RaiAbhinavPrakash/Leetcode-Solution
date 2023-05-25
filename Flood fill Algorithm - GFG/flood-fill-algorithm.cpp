//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        queue<pair<int,int>>q;
        q.push({sr, sc});
        int m = image.size(), n = image[0].size(), color = image[sr][sc];
        if(color == newColor) return image;
        image[sr][sc] = newColor;
        while(q.size())
        {
            int a = q.front().first, b = q.front().second;
            q.pop();
            if(a+1<m && image[a+1][b] == color)
            {
                q.push({a+1, b});
                image[a+1][b] = newColor;
            }
            if(a-1>=0 && image[a-1][b] == color)
            {
                q.push({a-1, b});
                image[a-1][b] = newColor;
            }
            if(b+1<n && image[a][b+1] == color)
            {
                q.push({a, b+1});
                image[a][b+1] = newColor;
            }
            if(b-1>=0 && image[a][b-1] == color)
            {
                q.push({a, b-1});
                image[a][b-1] = newColor;
            }
        }
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends