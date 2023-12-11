bool isSafe(int row,int col, vector<vector<int>> &board){
    // Horizontally check
    for(int i=0;i<board[0].size();i++){
        if(board[row][i]==1 && i!=col){
            return false;
        }
    }
    //vertically check
    for(int i=0;i<board.size();i++){
        if(board[i][col]==1 && i!=row){
            return false;
        }
    }

    // Check if there is a queen in the left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check if there is a queen in the right diagonal
    for (int i = row, j = col; i >= 0 && j < board.size(); i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

void solve(int row, vector<vector<int>> &board,vector<vector<int>> &ans){
    if(row == board.size()){
        vector<int> temp;
        for (int i = 0; i < board.size(); i++) {
          for (int j = 0; j < board[0].size(); j++){
              temp.push_back(board[i][j]);
          }
        }
        ans.push_back(temp);
        return;
    }

    for(int i=0;i<board.size();i++){
        if(isSafe(row,i,board)){
            // Place queen and move to the next row
            board[row][i] = 1;
            solve(row + 1, board, ans);
            // Backtrack: remove the queen to explore other possibilities
            board[row][i] = 0;
        }
    }
}

vector<vector<int>> nQueens(int n)
{
    vector<vector<int>> ans;
    vector<vector<int>> board(n,vector<int>(n,0));
    solve(0,board,ans);
    return ans;    
}

int main() {
    int n = 4; 
    vector<vector<int>> result = nQueens(n);

    // Display the result
    for (const auto &solution : result) {
        for (const auto &row : solution) {
            cout << row << " ";
        }
        cout << endl;
    }

    return 0;
}
