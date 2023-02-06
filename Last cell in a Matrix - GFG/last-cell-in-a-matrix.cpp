//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix, int R, int C){
        int i = 0, j = 0, u = 0, r = 1, d = 0, l = 0;
        while(i<R && j<C && i>=0 && j>=0)
        {
            if(matrix[i][j] == 0)
            {
                if(r) j++;
                else if(u) i--;
                else if(d) i++;
                else j--;
            }
            else
            {
                matrix[i][j] = 0;
                if(u)
                {
                    u = 0; r = 1; d = 0; l = 0;
                }
                else if(d)
                {
                    d = 0; l = 1; r = 0; u = 0;
                }
                else if(r)
                {
                    r = 0; d = 1; u = 0; l = 0;
                }
                else
                {
                    l = 0; u = 1; r = 0; d = 0;
                }
            }
        }
        if(i==R) return {i-1, j};
        else if(j==C) return {i, j-1};
        else if(i<0) return {i+1, j};
        else return {i, j+1};
    }
};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix, row, col);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends