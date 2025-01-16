#include <bits/stdc++.h>
using namespace std;

class SolveSudoku {
private:
    bool checksolver(vector<vector<char>> board , int row  , int column , char c){
        for(int i = 0; i<9 ; i++){
            if(board[row][i]==c){
                return false;
            }
            if(board[i][column]==c){
                return false;
            }
            if(board[3*(row/3) + i/3][3*(column/3)+i%3]==c){
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>> &board){
        for(int i = 0 ; i<9 ; i++){
            for(int j = 0 ; j<9 ; j++){
    
                if(board[i][j]=='.'){
                    for(char c = '1' ; c<='9' ; c++){
                        if(checksolver(board , i , j , c)==true){
                            board[i][j] = c;
                            if(solve(board)==true){
                                return true;
                            }
                            else{
                                board[i][j] = '.';
                            }
    
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<char>>sudoku;
    vector<char>row;
    char element;
    cout<<"Please enter the Sudoku to be solved: "<<"\n";
    for(int i = 0 ; i<9 ; i++){
        row={};
        for(int j = 0 ; j<9 ; j++){
            cin>>element;
            row.push_back(element);
        }
        sudoku.push_back(row);
    }
    SolveSudoku* checker = new SolveSudoku();
    checker->solveSudoku(sudoku);
    cout<<"The Sudoku's solution is:"<<"\n";
    for(int i = 0 ; i<9 ; i++){
        for(int j = 0 ; j<9 ; j++){
            cout<<sudoku[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
