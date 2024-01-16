#include "num-of-pairs-of-interchangeable-rectangles.h"

long long interchangeableRectangles(vector<vector<int>> &rectangles) {
    unordered_map<long double, int> map;
    double ratio;

    for(auto &rectangle : rectangles) {
        ratio = (double)rectangle[0] / rectangle[1];
        map[ratio]++;
    }

    long pairs = 0;
    long n;
    for(auto &m : map) {
        if(m.second <= 1) { continue;}
        n = m.second;
        pairs += (n * (n-1)) / 2;
    }

    return pairs;
}

void runNumOfPairsOfInterchangeableRectanglesExample() {
//    vector<vector<int>> rectangles = {{4, 8}, {3, 6}, {10, 20}, {15, 30}};
    vector<vector<int>> rectangles = {{4, 5}, {7, 8}};
    cout << "Number of pairs = " << interchangeableRectangles(rectangles) << endl;
}
