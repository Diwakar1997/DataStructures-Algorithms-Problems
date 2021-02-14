//https://leetcode.com/problems/spiral-matrix/solution/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if(rows == 0)
            return {};
        vector<int> result;
        int cols = matrix[0].size();
        int ur = 0, br = rows-1;
        int lc = 0, rc = cols-1;
        int n = rows*cols;
        
        while(n > 0) {
            for(int c = lc; c <= rc; c++) {
                result.push_back(matrix[ur][c]);
                n--;
                
            }
            ur++;
            if(n == 0)
                break;
            for(int r = ur; r <= br; r++) {
                result.push_back(matrix[r][rc]);
                n--;
            }
            rc--;
            if(n == 0)
                break;
            for(int c = rc; c >= lc; c--) {
                result.push_back(matrix[br][c]);
                n--;
            }
            if(n == 0)
                break;
            br--;
            for(int r = br; r >= ur; r--) {
                result.push_back(matrix[r][lc]);
                n--;
            }
            lc++;
        }
        return result;
    }
};