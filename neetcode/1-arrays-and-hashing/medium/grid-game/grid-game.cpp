#include "grid-game.h"

long long gridGame(vector<vector<int>> &grid) {
    int n = grid[0].size();
    vector<long> sufixRow1(n, 0);
    vector<long> prefixRow2(n, 0);

    long sum = 0;
    for(int i=n-1; i>=0; i--) {
        sufixRow1[i] = grid[0][i] + sum;
    }
    sufixRow1[0] = sum;

    sum = 0;
    for(int i=0; i<n; i++) {
        prefixRow2[i] = grid[1][i] + sum;
        sum += grid[1][i];
    }
    prefixRow2[n-1] = sum;

    long robot2max = INT32_MAX;
    long top, bottom;
    for(int i=0; i<n; i++) {
        if(i+1 < n) {
            top = sufixRow1[i+1];
        }else {
            top = 0;
        }
        if(i-1 >= 0) {
            bottom = prefixRow2[i-1];
        }else {
            bottom = 0;
        }

        robot2max = (long)min(robot2max, (long)max(top, bottom));
    }

    return robot2max;
}

void runGridGameExample() {
    vector<vector<int>> grid1 = {
            {2, 5, 4},
            {1, 5, 1}
    };

    cout << "Number of pts collected by robot 2 = " << gridGame(grid1) << endl;
}
