class Solution {
public:
    
    void traverse(vector<vector<int>>& image, int k, int sr, int sc, int color, int m, int n)
    {
        if(sr >= m || sr<0 || sc >= n || sc<0)
        {
             return;
        }
        if(image[sr][sc] != k)
        {
            return;
        }
        if(image[sr][sc] == color)
        {
             return;
        }
        image[sr][sc] = color;
        traverse(image, k, sr+1, sc, color, m, n);
        traverse(image, k, sr-1, sc, color, m, n);
        traverse(image, k, sr, sc+1, color, m, n);
        traverse(image, k, sr, sc-1, color, m, n);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int k = image[sr][sc];
        int m = image.size();
        if(m == 0) return image;
        int n = image[0].size();
        traverse(image, k, sr, sc, color, m, n);
        return image;
    }
};