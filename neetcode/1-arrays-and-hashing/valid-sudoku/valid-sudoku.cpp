#include "valid-sudoku.h"

bool isValidSudoku(vector<vector<char>> &board) {
    map<string, int> map;

    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            char c = board[i][j];
            if (c == '.') {
                continue;
            }
            string row = to_string(c) + " seen in row " + to_string(i);
            string col = to_string(c) + "seen in column " + to_string(j);
            string box = to_string(c) + " seen in box " + to_string(i/3) + " - " + to_string(j/3);

            if(map[row]++ || map[col]++ || map[box]++) {
                return false;
            }
        }
    }

    return true;
}

void runValidSudokuExample() {
    vector<vector<char>> validBoard {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    // First box contains duplicate 8
    vector<vector<char>> invalidBoard {
            {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    cout << "Is sudoku valid = " << isValidSudoku(validBoard) << endl;
    cout << "Is sudoku valid = " << isValidSudoku(invalidBoard) << endl;
}
