#include "brick-wall.h"

int leastBricksReview(vector<vector<int>> &wall) {
    if(wall.empty()) {return -1;}
    int width = 0;

    for(int w : wall[0]) {
        width += w;
    }

    int mostFreq = 0;
    unordered_map<int, int> map;
    int sum;
    for(auto & i : wall) {
        sum = 0;
        for(int j=0; j<i.size()-1; j++) {
           sum += i[j];
           map[sum]++;
        }
    }

    for(auto &m : map) {
        if(m.second <= 0) { continue;}
        mostFreq = max(mostFreq, m.second);
    }

    return wall.size() - mostFreq;
}

void runBrickWallExampleReview() {
//    vector<vector<int>> wall = {
//            {1, 2, 2, 1},
//            {3, 1, 2},
//            {1, 3, 2},
//            {2, 4},
//            {3, 1, 2},
//            {1, 3, 1, 1}
//    };
    vector<vector<int>> wall = {
            {1},
            {1},
            {1},
    };

    cout << "Minimum number of crossed bricks = " << leastBricksReview(wall) << endl;
}
