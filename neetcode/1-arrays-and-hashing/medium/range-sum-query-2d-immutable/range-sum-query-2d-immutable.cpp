#include "range-sum-query-2d-immutable.h"

class NumMatrix {
public:
    vector<vector<int>> prefixes;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size() + 1;
        int m = matrix[0].size() + 1;
        prefixes.resize(n, vector<int>(m, 0));

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i == 0 || j == 0) {
                    continue;
                }

                prefixes[i][j] = prefixes[i-1][j] + prefixes[i][j-1] + matrix[i-1][j-1] - prefixes[i-1][j-1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        row1 += 1, col1 += 1, row2 += 1, col2 += 1;
        int total = prefixes[row2][col2];
        int left = prefixes[row2][col1-1];
        int top = prefixes[row1-1][col2];
        int diff = prefixes[row1-1][col1-1];

        return total - (left + top) + diff;
    }
};

void runRangeSumQuery2dImmutableExample() {
    std::vector<std::vector<int>> matrix = {
            {3, 0, 1, 4, 2},
            {5, 6, 3, 2, 1},
            {1, 2, 0, 1, 5},
            {4, 1, 0, 1, 7},
            {1, 0, 3, 0, 5}
    };
//    std::vector<std::vector<int>> matrix = {
//            {1, 4, 1, 2, 0},
//            {5, 3, 3, 1, 0},
//            {3, 1, 2, 5, 2},
//            {0, 4, 1, 4, 3},
//            {1, 0, 3, 0, 5}
//    };
    NumMatrix numMatrix = NumMatrix(matrix);
    cout << "Sum = " << numMatrix.sumRegion(2, 1, 4, 3) << endl;
}
