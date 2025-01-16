#include <bits/stdc++.h>
using namespace std;

class SudokuCheck {
private:
    bool checksolver(vector<vector<char>> board , int row  , int column){
        for(int i = 0; i<9 ; i++){
            if(board[row][i]==board[row][column]&&column!=i){
                return false;
            }
            if(board[i][column]==board[row][column]&& i!=row){
                return false;
            }
            if(board[3*(row/3) + i/3][3*(column/3)+i%3]==board[row][column] && (row!=3*(row/3) + i/3 && column!=3*(column/3)+i%3)){
                return false;
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0 ; i<9 ; i++){
            for(int j = 0 ; j<9 ; j++){
                if(board[i][j]!='.'){
                    if(checksolver(board , i , j)==false){
                        //cout<<i<<" "<<j<<endl;
                        return false;
                    }
                }
            }
        }
        return true;
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

    SudokuCheck* checker = new SudokuCheck();
    bool possible = checker->isValidSudoku(sudoku);
    if(possible){
        cout<<"The sudoku is a valid sudoku"<<"\n";
    }
    else{
        cout<<"The given sudoku is invalid"<<"\n";
    }

    return 0;
}
