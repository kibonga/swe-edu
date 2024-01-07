#include "can-place-flowers.h"

bool canPlaceFlowers(vector<int> &flowerbed, int n) {

    if(n == 0) {
        return true;
    }

    // if (flowerbed.size() == 1 && flowerbed[0] == 0 && n == 1) {
    //     return true;
    // }

    // if (flowerbed.size() > 1 && flowerbed[0] == 0 && flowerbed[1] == 0) {
    //     flowerbed[0] = 1;
    //     n--;
    // }

    flowerbed.insert(flowerbed.begin(), 0);
    flowerbed.push_back(0);

    for (int i = 1; n > 0 && i < flowerbed.size()-1; i++) {
        if (flowerbed[i] == 1) {
            continue;
        }
        if (flowerbed[i - 1] == 1) {
            continue;
        }
        if (i + 1 < flowerbed.size() && flowerbed[i + 1] == 1) {
            continue;
        }
        flowerbed[i] = 1;
        n--;
    }

    return n == 0;
}

void runCanPlaceFlowersExample() {
    vector<int> flowerbed1 = {1, 0, 0, 0, 1};
    int n1 = 1;

    vector<int> flowerbed2 = {1, 0, 0, 0, 1};
    int n2 = 2;

    cout << "Can place flowers = " << canPlaceFlowers(flowerbed1, n1) << endl;
    cout << "Can place flowers = " << canPlaceFlowers(flowerbed2, n2) << endl;
}
