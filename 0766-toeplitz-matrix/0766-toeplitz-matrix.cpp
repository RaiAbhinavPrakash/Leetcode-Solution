class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int i, j, k, n = matrix.size(), m = matrix[0].size();
        for(k = 0; k < n; k++)
        {
            i = k, j = 0;
            int check = matrix[i][j];
            while(i<n && j<m)
            {
                if(check != matrix[i][j]) return false;
                i++; j++;
            }
        }
        for(k = 0; k<m; k++)
        {
            i = 0, j = k;
            int check = matrix[i][j];
            while(i<n && j<m)
            {
                if(check != matrix[i][j]) return false;
                i++; j++;
            }
        }
        return true;
    }
};