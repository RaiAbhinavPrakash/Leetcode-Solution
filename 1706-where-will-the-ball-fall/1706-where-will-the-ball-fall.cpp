class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int>ans;
        for(int i = 0; i<grid[0].size(); i++)
        {
            int j, k = i, f = 0;
            for(j = 0; j<grid.size(); j++)
            {
                if(k == 0 && grid[j][k] == -1)
                {
                    f = 1;
                    break;
                }
                else if(k == grid[0].size()-1 && grid[j][k] == 1)
                {
                    f = 1;
                    break;
                }
                else if(grid[j][k] == 1  &&  grid[j][k+1] == -1)
                {
                    f = 1;
                    break;
                }
                else if(grid[j][k] == -1  &&  grid[j][k-1] == 1)
                {
                    f = 1;
                    break;
                }
                else if(grid[j][k] == 1)
                {
                    k++;
                }
                else if(grid[j][k] == -1)
                {
                    k--;
                }
            }
            if(f) ans.push_back(-1);
            else ans.push_back(k);
        }
        return ans;
    }
};