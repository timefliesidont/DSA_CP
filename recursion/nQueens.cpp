#include <iostream>

using namespace std;

bool placeQueen(vector<vector<int>>& board, int i, int j){
    int j_left=j, j_right=j;
    int n = board.size();

    while(i >= 0){
        if((j_left >= 0 && board[i][j_left] == 1) || (board[i][j] == 1) || (j_right < n && board[i][j_right] == 1))
            return false;
        i--;
        j_left--;
        j_right++;
    }

    return true;
}

int nQueens(vector<vector<int>>& board, int i, int n){
    if(i == n)
        return 1;

    int nb_solutions=0;
    for(int j = 0; j<n; j++){
        if(placeQueen(board, i, j)){
            board[i][j] = 1;
            nb_solutions += nQueens(board, i+1, n);
            board[i][j] = 0;
        }
    }

    return nb_solutions;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    cout << nQueens(board, 0, n);
}
