class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            vector<int> seen(10);
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                if (seen[board[i][j] - '0']) return false;
                seen[board[i][j] - '0']++;
            }
            seen = vector<int>(10);
            for (int j = 0; j < 9; j++) {
                if (board[j][i] == '.') continue;
                if (seen[board[j][i] - '0']) return false;
                seen[board[j][i] - '0']++;
            }
            seen = vector<int>(10);
            for (int j = 0; j < 9; j++) {
                if (board[i / 3 * 3 + j / 3][i % 3 * 3 + j % 3] == '.') continue;
                if (seen[board[i / 3 * 3 + j / 3][i % 3 * 3 + j % 3] - '0']) return false;
                seen[board[i / 3 * 3 + j / 3][i % 3 * 3 + j % 3] - '0']++;
            }
        }
        return true;
    }
};