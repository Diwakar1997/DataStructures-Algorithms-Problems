//https://leetcode.com/problems/n-queens/
class Solution {
public:
    vector<vector<string>> result;

    bool isSafe(int r, int c, vector<vector<int>> board, int n) {
        for(int i = 0; i < c; i++) {
            if(board[r][i] == 1)
                return false;
        }
        for(int i = r-1, j = c-1; i >= 0 && j >= 0; i--, j--) {
            if(board[i][j] == 1)
                return false;
        }
        for(int i = r+1,j = c-1; i < n && j >= 0; i++, j--) {
            if(board[i][j] == 1)
                return false;
        }
        
        return true;
    }
    
    void solve(int n, int c, vector<vector<int>> board) {
        if(c == n) {
            vector<string> s;
            for(vector<int> vec : board) {
                string curr = "";
                for(int i : vec) {
                    if(i == 0) {
                        curr += '.';
                    }
                    else {
                        curr += 'Q';
                    }
                }
                s.push_back(curr);
            }
            
            result.push_back(s);
            return;
        }
        
        for(int i = 0; i < n; i++) {
            if(isSafe(i, c, board, n)) {
                board[i][c] = 1;
                solve(n, c + 1, board);
                board[i][c] = 0;
            }
        }
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> board(n, vector<int>(n, 0)); 
        solve(n,0, board);
        
        return result;
    }
};