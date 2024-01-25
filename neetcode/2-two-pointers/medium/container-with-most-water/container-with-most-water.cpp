#include "container-with-most-water.h"

int maxAreaMedium(vector<int> &height) {
    int i=0, j=height.size()-1;
    int maxArea = INT32_MIN;
    int area;

    while(i < j) {
        area = (j-i) * min(height[i], height[j]);
        maxArea = max(maxArea, area);
        if(height[i] < height[j]) {
            i++;
        }else {
            j--;
        }
    }

    return maxArea;
}

void runContainerWithMostWaterMediumExample() {
    vector<int> n1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Max area = " << maxAreaMedium(n1) << endl;
}
