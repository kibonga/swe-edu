#include "pascals-triangle.h"

vector<vector<int>> generatePascalsTriangle(int numRows) {
    vector<vector<int>> result;
    result.reserve(numRows);

    result.push_back({1});
    if(numRows == 1) {return result;}

    for(int i=1; i<numRows; i++) {
        vector<int> row(i+1, 1);
        for(int j=1; j<i; j++) {
            row[j] = result[i-1][j-1] + result[i-1][j];
        }
        result.push_back(row);
    }

    return result;
}

void runPascalsTriangleExample() {
    int k = 5;
    vector<vector<int>> result = generatePascalsTriangle(k);
    cout << "Pascals triangle = [ " << endl;
    for(auto &row : result) {
        cout << "[ ";
        for(int r : row) {
            cout << r << " ";
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;
}
