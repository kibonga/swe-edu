#include "number-of-pairs-of-interchangeable-rectangles.h"

long long interchangeableRectanglesReviewFri19Jan2024(vector<vector<int>> &rectangles) {
    unordered_map<double, int> ratios;
    long count = 0;

    int a, b;
    for(auto r : rectangles) {
        a = r[0];
        b = r[1];
        ratios[(double)a/b]++;
    }

    long n;
    for(auto r : ratios) {
        n = r.second;
        count += (long)(n * (n-1)) / 2;
    }

    return count;
}

void runNumOfPairsOfInterchangeableRectanglesExampleReviewFri19Jan2024() {
    vector<vector<int>> rectangles = {
            {4, 8},
            {3, 6},
            {10, 20},
            {15, 30}
    };
    cout << "Number of rectangles = " << interchangeableRectanglesReviewFri19Jan2024(rectangles) << endl;
}
