#include "brick-wall.h"

int leastBricks(vector<vector<int>> &wall) {
    if(wall.empty()) {
        return -1;
    }
    unordered_map<int, int> map;
    int width = 0;
    for(int i : wall[0]) {
        width += i;
    }

    int sum;
    for(auto &w : wall) {
        sum = 0;
        for(int i=0; i<w.size()-1; i++) {
           sum += w[i];
           map[sum]++;
        }
    }

    int count = 0;
    for(auto &m : map) {
        count = max(m.second, count);
    }

    return wall.size() - count;
}

void runBrickWallExample() {
//    vector<vector<int>> wall = {
//            {1, 2, 2, 1},
//            {3, 1, 2},
//            {1, 3, 2},
//            {2, 4},
//            {3, 1, 2},
//            {1, 3, 1, 1}
//    };

    vector<vector<int>> wall {
            {1},
            {1},
            {1}
    };

    cout << "Min num of crossed bricks = " << leastBricks(wall) << endl;
}
